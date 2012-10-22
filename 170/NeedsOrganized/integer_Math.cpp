#include <iostream.h>

void main()
{
	int i = 50;
	float f = 100.25;

	cout << "i = " << i << endl;
	cout << "f = " << f << endl;

	i = f;
	cout << "i = " << i << endl;

	f = 1/2;
	cout << "f = " << f << endl;

	f = 1.0/2.0;
	cout << "f = " << f << endl;

	f = 1/2.0;
	cout << "f = " << f << endl;
	
	f = 3.5;
	i = 2;

	f = f/i;
	cout << "f = " << f << endl;

	f = 1.25;
	i = 2;

	f = i * f;
	cout << "f = " << f << endl;

	f = i + f;
	cout << "f = " << f << endl;

	f = 1 + 2;
	cout << "f = " << f << endl;

}