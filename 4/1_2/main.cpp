#include <utils/minMax.h>
#include <utils/print.h>
#include <utils/readShapes.h>
#include <vector>

using namespace std;

int main()
{
	vector<shared_ptr<IShape>> shapes = ReadShapes(cin);
	PrintShapes(cout, shapes);
	if (!shapes.empty())
	{
		cout << "max area: " << GetMaxAreaShape(shapes)->ToString() << '\n';
		cout << "min perimeter: " << GetMinPerimeterShape(shapes)->ToString() << '\n';
	}

	return 0;
}