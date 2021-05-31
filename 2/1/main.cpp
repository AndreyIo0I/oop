#include <vector>
#include "src/vectorBasics.h"

using namespace std;

int main()
{
    vector<float> v;

    readVector(v);
    addMeanOfPositiveElements(v);
    printAscVector(v);

    return 0;
}