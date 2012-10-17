#include<iostream>
using namespace std;

void main()
{
	//array of integers
	int i[] = {0,1,2};
	cout << i << endl;

	//array of characters
	char j[] = {'E','L','I'};
	cout << j << endl;

	//c-style string
	char x[] = {'E','L','I','\0'};
	cout << x << endl;

	//c-style string (but the 0 should be a '\0')
	char y[] = {'E','L','I',0};
	cout << y << endl;

	//c-style string
	char e[] = "ELI";
	cout << e << endl;
}
