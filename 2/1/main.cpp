#include <vector>
#include <algorithm>
#include "src/vectorBasics.h"

using namespace std;

int main()
{
    vector<float> v;

    ReadVector(v);
    AddMeanOfPositiveElements(v);
	sort(v.begin(), v.end());
	PrintVector(v);

    return 0;
}