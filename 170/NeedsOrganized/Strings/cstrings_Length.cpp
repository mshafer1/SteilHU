//This program counts the number of characters in a c-
//style string before the null terminator

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//The c-style string parameter is received as a constant
//character array. This is a promise that the function 
//will not change the array. It helps make the code more
//readable and prevents programming errors.

int length(const char s[])
{
	int length = 0;

	while(s[length] != '\0')
	{
		length++;
	}
	return length;
}

int main()
{
	char s[100];
	cout << "Enter a word: ";
	cin >> s;
	cin.ignore();

	cout << s << " contains " << length(s) << " characters." << endl;

	cin.get();
	return 0;
	
	
}








