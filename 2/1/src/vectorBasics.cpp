#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void AddMeanOfPositiveElements(vector<float> & v)
{
    int amount = 0;
    float sumOfPositiveElements = 0;
    for (auto x : v)
    {
        if (x > 0)
        {
            sumOfPositiveElements += x;
            amount++;
        }
    }
    if (amount > 0)
    {
        float mean = sumOfPositiveElements / static_cast<float>(amount);
        for (auto & x : v)
            x += mean;
    }
}

void ReadVector(std::istream & input, vector<float> & v)
{
    float x;

    while (input >> x)
        v.push_back(x);
}

void PrintVector(std::ostream & output, vector<float> & v)
{
    if (!v.empty())
    {
        output << *v.begin();
        for (auto x = ++v.begin(); x < v.end(); ++x)
            output << ' ' << *x;
		output << '\n';
    }
}

void GetSortedModifiedVector(std::istream & input, std::ostream & output)
{
    vector<float> v;

    ReadVector(input, v);
    AddMeanOfPositiveElements(v);
    sort(v.begin(), v.end());
    PrintVector(output, v);
}
