#include<iostream>
using namespace std;

void main()
{
	//endl - add carriage return and flush
	// how to flush endl, cin, end of the program, cout.flush
	//cout << "Hello World" << endl;
	//cout.flush();
	
	//  \n  - escape sequence for carriage return 
	//  \\ - escape sequence for a backslash
	//	\t - tab
	//  \b - backspace
	//  \a - alarm
	//cout << "Hello World\nStuff";

	short s;  // 16 bit integer (+- 2^15)
	int i;  // 32 bit integer (+- 2^31)
	long l;  // same as int

	//cin >> i;
	//cout << i << endl;
	//i = 2147483647;
	//cout << i << endl;

	float f; //32 bit floating point number
	cin >> f;
	//by default floats display 6 significant digits
	cout << f << endl;
	//cout.precision(2);
	//setf to set flags
	//unsetf to set flags
	cout.setf(ios_base::showpoint | ios_base::fixed);
	cout << f << endl;
	cout << ios_base::showpoint << endl;
	cout << ios_base::fixed << endl;
	cout << (ios_base::showpoint | ios_base::fixed) << endl;
	
	//bit wise or
	cout << (2|4) << endl;
	cout << (6|4) << endl;

	system("Pause");
}
