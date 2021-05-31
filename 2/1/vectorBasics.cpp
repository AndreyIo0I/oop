#include "vectorBasics.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void addMeanOfPositiveElements(vector<float> & v)
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

void readVector(vector<float> & v)
{
    float x;

    while (cin >> x)
        v.push_back(x);
}

void printAscVector(vector<float> & v)
{
    if (!v.empty())
    {
        sort(v.begin(), v.end());
        cout << *v.begin();
        for (auto x = ++v.begin(); x < v.end(); x++)
            cout << ' ' << *x;
    }
    cout << '\n';
}

int main() {
    vector<float> v;

    readVector(v);
    addMeanOfPositiveElements(v);
    printAscVector(v);

    return 0;
}