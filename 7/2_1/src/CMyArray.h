#pragma once

#include <algorithm>
#include <iostream>
#include <new>
#include <stdexcept>

template <typename T>
class CMyArray
{
	template <bool IsConst>
	class IteratorBase
	{
		friend class IteratorBase<true>;
	public:
		using MyType = IteratorBase<IsConst>;
		using value_type = std::conditional_t<IsConst, const T, T>;
		using reference = value_type&;
		using pointer = value_type*;
		using difference_type = ptrdiff_t;
		using iterator_category = std::random_access_iterator_tag;

		IteratorBase() = default;
		IteratorBase(const IteratorBase<false>& other)
			: m_item(other.m_item)
		{
		}

		pointer operator->()
		{
			return &this;
		}

		reference& operator*() const
		{
			return *m_item;
		}

		MyType& operator+=(difference_type offset)
		{
			m_item += offset;
			return *this;
		}

		MyType& operator-=(difference_type offset)
		{
			m_item -= offset;
			return *this;
		}

		MyType operator+(difference_type offset) const
		{
			MyType self(m_item);
			return self += offset;
		}

		MyType operator-(difference_type offset) const
		{
			MyType self(m_item);
			return self -= offset;
		}

		difference_type operator-(const MyType& other) const
		{
			return m_item - other.m_item;
		}

		reference& operator[](difference_type offset)
		{
			return *(m_item[offset]);
		}

		bool operator==(const MyType& itr) const
		{
			return m_item == itr.m_item;
		}

		bool operator!=(const MyType& itr)  const
		{
			return m_item != itr.m_item;
		}

		MyType operator++()
		{
			++m_item;
			return *this;
		}

		const MyType operator++(int)
		{
			MyType tmp(*this);
			++m_item;
			return tmp;
		}

		MyType operator--()
		{
			--m_item;
			return *this;
		}

		const MyType operator--(int)
		{
			MyType tmp(*this);
			--m_item;
			return tmp;
		}

		friend MyType operator+(difference_type offset, const MyType& it)
		{
			return it + offset;
		}

		friend MyType operator-(difference_type offset, const MyType& it)
		{
			return it - offset;
		}

	public:
		IteratorBase(T* item)
			: m_item(item)
		{
		}

	protected:
		T* m_item = nullptr;
	};

public:
	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size); // todo проверить с выбросом ошибки
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end); // todo добавить восстановление прошлых элементов
				throw;
			}
		}
	}

	CMyArray(const CMyArray&& arr) noexcept
		: m_begin(arr.m_begin)
		, m_end(arr.m_end)
		, m_endOfCapacity(arr.m_endOfCapacity)
	{
		arr.m_begin = nullptr;
		arr.m_end = nullptr;
		arr.m_endOfCapacity = nullptr;
	}

	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// Конструируем копию value по адресу newItemLocation
				new (newEnd) T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// Переключаемся на использование нового хранилища элементов
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	T& GetBack()
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	const T& GetBack() const
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}

	T& operator[](size_t i)
	{
		if (i >= GetSize())
			throw std::out_of_range("out of range");
		return m_begin[i];
	}

	T& operator[](size_t i) const
	{
		if (i >= GetSize())
			throw std::out_of_range("out of range");
		return m_begin[i];
	}

	CMyArray& operator=(CMyArray&& arr) noexcept
	{
		if (&arr != this)
		{
			DeleteItems(m_begin, m_end);
			m_begin = arr.m_begin;
			m_end = arr.m_end;
			m_endOfCapacity = arr.m_endOfCapacity;

			arr.m_begin = nullptr;
			arr.m_end = nullptr;
			arr.m_endOfCapacity = nullptr;
		}
		return *this;
	}

	CMyArray& operator=(const CMyArray& arr)
	{
		if (&arr != this)
		{
			*this = CMyArray(arr);
		}
		return *this;
	}

	void Resize(size_t size)
	{
		if (size > GetCapacity())
		{
			auto newBegin = RawAlloc(size);
			auto newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				for (; newEnd != newBegin + size; ++newEnd)
					new (newEnd)T();
				DeleteItems(m_begin, m_end);
				m_begin = newBegin;
				m_end = newEnd;
				m_endOfCapacity = newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
		}
		else if (size > GetSize())
		{
			auto newEnd = m_end;
			try
			{
				for (; newEnd != m_begin + size; ++newEnd)
					new (newEnd)T();
			}
			catch (...)
			{
				DestroyItems(m_end, newEnd);
				throw;
			}
		}
		else
		{
			auto newEnd = m_begin + size;
			DestroyItems(newEnd, m_end);
			m_end = newEnd;
		}
	}

	void Clear()
	{
		DestroyItems(m_begin, m_end);
		m_end = m_begin;
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

	using iterator = IteratorBase<false>;
	using const_iterator = IteratorBase<true>;

	iterator begin() { return { m_begin }; }

	const_iterator cbegin() const { return { m_begin }; }

	iterator end() { return { m_end }; }

	const_iterator cend() const { return { m_end }; }

	auto rbegin() { return std::reverse_iterator<T*>(m_end); }

	auto crbegin() const { return std::reverse_iterator<T*>(m_end); }

	auto rend() { return std::reverse_iterator<T*>(m_begin); }

	auto crend() const { return std::reverse_iterator<T*>(m_begin); }

private:
	static void DeleteItems(T *begin, T *end)
	{
		// Разрушаем старые элементы
		DestroyItems(begin, end);
		// Освобождаем область памяти для их хранения
		RawDealloc(begin);
	}

	// Копирует элементы из текущего вектора в to, возвращает newEnd
	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd) T(*srcBegin);
		}
	}

	static void DestroyItems(T* from, T* to)
	{
		// dst - адрес объект, при конструирование которого было выброшено исключение
		// to - первый скорнструированный объект
		while (to != from)
		{
			--to;
			// явно вызываем деструктор для шаблонного типа T
			to->~T();
		}
	}

	static T* RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T* p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T* p)
	{
		free(p);
	}

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};
