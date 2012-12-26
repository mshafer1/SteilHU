//this program uses the strnicmp() function to compare two strings
	
//strnicmp returns 0 if the two strings are identical through n characters, case insensitive
	//note the 'n' and the 'i'
	//don't make the mistake of switching the 'i' and the 'n'. strincmp() does not exist.
	

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//experiment during runtime.
	cout << "strnicmp\nEnter \"quit\" as a string to quit.\n";
	char s1[100];
	char s2[100];
	
	while(strnicmp(s1, "quit", 4) != 0 && strnicmp(s2, "quit", 4) != 0)
	{
		cout << "\nString 1? ";
		cin.getline(s1, 100);
		
		cout << "String 2? ";
		cin.getline(s2, 100);
		
		int n = 0;
		cout << "Number of characters to compare? ";
		cin >> n;
		cin.ignore(); //ignore the carriage return that was left by the >> operation above
	
		if(strnicmp(s1, s2, n) == 0) // returns 0 if the first n characters are the same, case insensitive
		{
			cout << "They are the same" <<endl;
		}
		
		else if (strnicmp(s1,s2, n) > 0)
		{
			cout << s1 << " is \"greater\" than " << s2 << endl; 
		}
		
		else if (strnicmp(s1,s2, n) < 0)
		{
			cout << s1 << " is \"less\" than " << s2 << endl; 
		}
	}
		return 0;
}
