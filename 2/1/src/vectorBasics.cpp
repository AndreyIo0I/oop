#include <vector>
#include <iostream>

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

void ReadVector(vector<float> & v)
{
    float x;

    while (cin >> x)
        v.push_back(x);
}

void PrintVector(vector<float> &v)
{
    if (!v.empty())
    {
        cout << *v.begin();
        for (auto x = ++v.begin(); x < v.end(); ++x)
            cout << ' ' << *x;
    }
    cout << '\n';
}
