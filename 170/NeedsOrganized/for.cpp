#include<iostream>
#include<iomanip>

using namespace std;

void main()
{
	for( int i = 0; i <= 255; i++ )
	{
		cout << setw(5) << i << setw(5) << (char)i << endl;
	}
	
	//for( char c  = 'A'; c <= 'z'; c++ )
	//{
	//	int i = c;
	//	cout << setw(5) << i << setw(5) << c << endl;
	//}

}




