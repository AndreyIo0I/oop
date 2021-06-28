#include <Vector.h>
#include <iostream>

using namespace std;

int main()
{
	CVector3D v(1, 2, 3);
	v.Normalize();
	cout << v.GetLength() << '\n';
	cout << v;
	return 0;
}