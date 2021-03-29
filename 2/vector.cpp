#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void addMean(vector<float> &v) {
    int amount = 0;
    float mean = 0;
    for (float x : v) {
        if (x > 0)
        {
            mean += trunc(x * 1000) / 1000;
            amount++;
        }
    }
    if (amount > 0)
        mean /= amount;
    for (auto x = v.begin(); x < v.end(); x++)
        *x += mean;
}

void readVector(vector<float> &v)
{
    float x;

    while (cin >> x)
        v.push_back(x);
}

void printAscVector(vector<float> &v)
{
    if (!v.empty())
    {
        sort(v.begin(), v.end());
        cout << *v.begin();
        for (auto x = ++v.begin(); x < v.end(); x++)
            cout << " " << *x;
    }
    cout << "\n";
}

int main() {
    vector<float> v;

    readVector(v);
    addMean(v);
    printAscVector(v);

    return 0;
}