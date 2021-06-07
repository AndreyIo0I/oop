#include <vector>
#include <algorithm>
#include "src/vectorBasics.h"

using namespace std;

int main()
{
    vector<float> v;

    readVector(v);
    addMeanOfPositiveElements(v);
	sort(v.begin(), v.end());
	printVector(v);

    return 0;
}