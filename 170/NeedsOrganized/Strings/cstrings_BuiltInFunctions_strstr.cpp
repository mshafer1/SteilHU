//this program uses the strstr() function to find a string in a string

	//strstr(char a[], char b[]) returns the pointer of the first instance of the c-style string b in c-style string a.
	
	//this function does not search for the null terminator at the end of
	//	the query string
	
	//if the string is not found, the pointer NULL is returned.

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	
	//examine the code to see how strstr() is used
	//experiment during runtime.
	
	cout << "strstr\nEnter \"quit\" as a string to quit.\n";
	char s1[100];
	char s2[100];
	
	while(strcmp(s1, "quit") != 0 && strcmp(s2, "quit") != 0)
	{
		cout << "\nString 1? ";
		cin.getline(s1, 100);
		
		cout << "String 2? ";
		cin.getline(s2, 100);
	
		if(strstr(s1, s2) != NULL)
		{
			cout << "\"" << s2 << "\" begins at character ";
			cout << (strstr(s1, s2) - s1) + 1 << " in \"" << s1 << "\". "<< endl; 
				//pointer minus a pointer
		}
		else
		{
			cout << "\"" << s2 << "\" not found in \"" << s1 << "\"." << endl; 
		}
	}
	return 0;
}