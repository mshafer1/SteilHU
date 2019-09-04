//this program uses the stricmp() function to compare two strings
	
//stricmp returns 0 if the two strings are the same, but the comparison is case insensitive
	//note the "i" in strncmp (think 'i' stands for "insensitive")

#if !defined(_WIN32) && !defined (_MSC_VER)
#define stricmp strcasecmp
#endif
	
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//experiment during runtime.
	cout << "stricmp\nEnter \"quit\" as a string to quit.\n";
	char s1[100];
	char s2[100];
	
	while(stricmp(s1, "quit") != 0 && stricmp(s2, "quit") != 0)
	{
		cout << "\nString 1? ";
		cin.getline(s1, 100);
		
		cout << "String 2? ";
		cin.getline(s2, 100);
	
		if(stricmp(s1, s2) == 0) 	// returns 0 if the c-style strings are the same, case insensitive
		{
			cout << "They are the same" <<endl;
		}
		
		else if (stricmp(s1,s2) > 0)
		{
			cout << s1 << " is \"greater\" than " << s2 << endl; 
		}
		
		else if (stricmp(s1,s2) < 0)
		{
			cout << s1 << " is \"less\" than " << s2 << endl; 
		}
	}
		return 0;
}
