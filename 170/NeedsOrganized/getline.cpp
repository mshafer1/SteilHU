#include<iostream>
#include<time.h>

using namespace std;

//string - a grouping of characters to form a word or phrase in a program
// a c-style string - array of charcters whose end is marked by the "null terminator" '\0'
//null terminator ('\0') - has an ascii value of 0, marks the end of strings


void getString( const char prompt[], char s[], int sLength )
{
	////get line gets characters until the "end of line character" or there is no more room in the string
	////if there are more charactes input than the string can hold a fail flag is set
	////when the fail flag is set cin will not work anymore until cin.clear() is called
	////you can use cin.fail() to see if it failed
	do
	{
		//clears the error flag
		cin.clear();
		//find the number of characters in the input buffer
		int ingonreCount = cin.rdbuf()->in_avail();
		//throw away n characters from the input buffer
		cin.ignore(ingonreCount);

		cout << prompt;
		//get the first sLenght -1 characters from the input buffer and put then in the array s
		cin.getline(s,sLength);
	}
	while(cin.fail());
}

void main()
{
	char s[10] = "abcdefghi";
	
	getString("Name? ",s,10);

	cout << "First stuff - " << s << endl;

	int x;
	cin >> x;
	cout << "Second stuff - " << x << endl;
}