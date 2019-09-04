//this program compares two c-style strings without using the built-in functions.

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int stringCompare(const char s1[], const char s2[]) //const is used because this
{													//function must not change the strings
	int Result = 0;
	int i = 0;

	while(s1[i] != '\0' && s2[i] != '\0' && Result == 0)
	{
		 Result = s1[i] - s2[i];
		 i++;
	}

	if (Result == 0)
	{
		Result = s1[i] - s2[i];
	}

	return Result; //returns 0 if they are the same.
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
	
	if(stringCompare(s1, s2) == 0)
	{
		cout << "Same.";
	}
	else
	{
		cout << "Not same.";
	}
	
	cin.get();
	return 0;
}