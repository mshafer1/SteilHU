//this program uses the strcmp() function to compare two strings

//strcmp returns 0 if the two c-style strings are exactly the same.

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//experiment during runtime.
	cout << "strcmp\nEnter \"quit\" as a string to quit.\n";
	char s1[100];
	char s2[100];
	
	while(strcmp(s1, "quit") != 0 && strcmp(s2, "quit") != 0)
	{
		cout << "\nString 1? ";
		cin.getline(s1, 100);
		
		cout << "String 2? ";
		cin.getline(s2, 100);
	
		if(strcmp(s1, s2) == 0) // returns 0 if the strings are identical
		{
			cout << "They are the same" <<endl;
		}
		
		else if (strcmp(s1,s2) > 0)
		{
			cout << s1 << " is \"greater\" than " << s2 << endl; 
		}
		
		else if (strcmp(s1,s2) < 0)
		{
			cout << s1 << " is \"less\" than " << s2 << endl; 
		}
	}
		return 0;
}