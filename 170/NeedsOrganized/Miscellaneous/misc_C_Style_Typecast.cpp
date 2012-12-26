//this program covers c-style casting

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void ITakeShort(short s)
{
	cout << s << endl;
}


int main()
{

	char c = 'c';		//1 byte
	bool b = true;		//1 byte
	short s = 123;	//2 bytes
	int i = 2000000000;		//4 bytes could be 2
	long l = 2000000000;		//4 bytes
	unsigned long ul= 4000000000; //4 bytes
	float f = 1.0f/3;//1123456.6789123;//4 bytes
	double d = 1.0/3;//1123456.6789123;	//8 bytes

	ITakeShort((short)l); // cast l as type short

	cout.precision(25);

	cout << f << endl;
	cout << (double)f << endl;  //cast f as type double

	cout << d << endl;
	cout << (float) d << endl;
	cout << (int) d << endl;

	cout << (short)i << endl;

    cin.get();
    return 0;
}
