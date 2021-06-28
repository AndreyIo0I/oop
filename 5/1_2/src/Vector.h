#pragma once

class CVector3D
{
public:
	// Конструирует нулевой вектор
	CVector3D();

	// Конструирует вектор с заданными координатами
	CVector3D(double x0, double y0, double z0);

	// Возвращает длину вектора
	double GetLength() const;

	// Нормализует вектор (приводит его к единичной длине)
	void Normalize();

	// Другие методы и операции класса

	// В данном случае данные можно сделать публичными
	double x, y, z;
};
