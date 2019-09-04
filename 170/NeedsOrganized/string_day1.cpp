#include<iostream>
#include<time.h>

using namespace std;

//string - a grouping of characters to form a word or phrase in a program
// a c-style string - array of charcters whose end is marked by the "null terminator" '\0'
//null terminator ('\0') - has an ascii value of 0, marks the end of strings

void main()
{
	char s[100];

	s[0] = 'E';
	s[1] = 'l';
	s[2] = 'i';
	s[3] = '\0';

	cout << s << endl;

	char s2[100] = {'E','m','m','a'};
	cout << s2 << endl;

	// you can only initalize a string using the "=" at the declaration
	char s3[100] = "Eden";
	cout << s3 << endl;

//	s3 = "Bob";
	cout << s3 << endl;


	//char firstName[50];
	//char lastName[50];
	//cin.setf(ios::skipws);
	//cout << "What is your name? ";
	//cin >> firstName;
	//cin >> lastName;
	//cout << "Hi " << lastName << ", " << firstName;


	char phrase[100];
	cin.getline( phrase, 100);
	cout << phrase;
}