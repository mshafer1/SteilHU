#include<iostream>
using namespace std;

//The String Lenght function counts the number of
//characters in the array before the null terminator

//The c-style string is passed to the funciton as a constant
//character array.  This is a promise that the function will
//not change the array.

int length(const char s[])
{
	int length = 0;

	while(s[length] != '\0')
	{
		length++;
	}
	return length;
}

void main()
{
	char s[100];
	cin >> s;
	cout << length(s) << endl;
	cout << length("Hi there bob") << endl;
}








