//this program uses the strncmp() function to compare two strings
	
//strncmp returns 0 if the two strings are identical through n characters
	//note the 'n' (think 'n' stands for "number")
	

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//experiment during runtime.
	cout << "strncmp\nEnter \"quit\" as a string to quit.\n";
	char s1[100];
	char s2[100];
	
	while(strncmp(s1, "quit", 4) != 0 && strncmp(s2, "quit", 4) != 0)
	{
		cout << "\nString 1? ";
		cin.getline(s1, 100);
		
		cout << "String 2? ";
		cin.getline(s2, 100);
		
		int n = 0;
		cout << "Number of characters to compare? ";
		cin >> n;
		cin.ignore(); //ignore the carriage return that was left by the >> operation above
	
		if(strncmp(s1, s2, n) == 0) // returns 0 if the first n characters are the same
		{
			cout << "They are the same" <<endl;
		}
		
		else if (strncmp(s1,s2, n) > 0)
		{
			cout << s1 << " is \"greater\" than " << s2 << endl; 
		}
		
		else if (strncmp(s1,s2, n) < 0)
		{
			cout << s1 << " is \"less\" than " << s2 << endl; 
		}
	}
		return 0;
}
