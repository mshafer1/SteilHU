#include<iostream>
#include<iomanip>

using namespace std;

void displayAsMoney( float money )
{
	int originalPrecision = cout.precision();

	int originalFlags = cout.flags();

	cout.precision(2);
	cout.setf(ios_base::fixed);
	cout << "$" << money << endl;

	cout.precision( originalPrecision );
	if( originalFlags != cout.flags() )
	{
		cout.unsetf(ios_base::fixed);
	}
}

void main()
{
	float f;
	cin >> f;
	cout << f << endl;
	displayAsMoney( f );
	cout << f << endl;
}
