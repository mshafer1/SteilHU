#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

template<typename  typeName>
void myswap(typeName& i, typeName& j)
{
	typeName temp = i;
	i = j;
	j = temp;
}

void main()
{
	double x;
	double y;

	cin >> x;
	cin >> y;

	myswap(x, y);

	cout << x << endl;
	cout << y << endl;
}
