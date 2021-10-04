#include <utils/minMax.hpp>
#include <utils/print.hpp>
#include <utils/readShapes.hpp>
#include <vector>

using namespace std;

int main()
{
	vector<unique_ptr<IShape>> shapes = ReadShapes(cin);
	PrintShapes(cout, shapes);
	if (!shapes.empty())
	{
		cout << "=================================================================\n";
		cout << "max area: " << GetMaxAreaShape(shapes)->ToString() << '\n';
		cout << "min perimeter: " << GetMinPerimeterShape(shapes)->ToString() << '\n';
	}

	return 0;
}