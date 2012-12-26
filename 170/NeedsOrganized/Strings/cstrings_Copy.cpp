//this program copies the contents of one c-style string into another,
//	without using the built-in functions.

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int length(const char s[])
{
	int length = 0;

	while(s[length] != '\0')
	{
		length++;
	}
	return length;
}

void copy( char destination[], const char source[] )
{
	int i;
	for(i = 0; source[i] != '\0'; i++)
	//for(i = 0; i < length(source); i++) also works
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

int main()
{
	cout << "String 1: ";
	char s1[50] = {'\0'};
	cin.get(s1, 50); //get up to 50 chars, store in s1
	cin.ignore(); //ignore the carriage return
	
	cout << "String 2: ";
	char s2[50] = {'\0'};
	cin.get(s2, 50);
	cin.ignore();
	
	copy(s2,s1);
	cout << "String 2 is now \"" << s2 << '\"';
	
	cin.get();
	return 0;
}









