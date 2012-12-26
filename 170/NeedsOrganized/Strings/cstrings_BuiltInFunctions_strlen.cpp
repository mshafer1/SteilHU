//this program uses the strlen() function to find the length of a c-style string

#include<iostream>
#include<cstring>

using std::cout;
using std::cin;

int main()
{
	char s[50];
	cout << "Enter word or phrase to get its length: ";
	cin.getline(s,50); //gets one line, up to 50 characters, and stores it in s
	cout << '"' << s <<  "\" is " << strlen(s) << " characters long\n"; 
		
//	strlen() returns the length of a c-style string

	cin.get();
	return 0;
}
//notice the escape sequences?