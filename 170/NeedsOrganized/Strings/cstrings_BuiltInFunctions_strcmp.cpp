//this program uses the strcmp() function to compare two strings

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//experiment with ascii values during runtime.
	
	char s1[50] = "Apple"; 
	char s2[50] = "apple";
	if(strcmp(s1,s2) == 0) //returns 0 if they are the same
	{
		cout << "They are the same" << endl;
	}
	else if (strcmp(s1,s2) > 0)
	{
		cout << s1 << " is greater than " << s2 << endl; // strcmp() compares ASCII values
	}
	else if (strcmp(s1,s2) < 0)
	{
		cout << s1 << " is less than " << s2 << endl; 
	}
	cin.get();
		
//experiment with it!	
	
		/* cout << "string 1? ";
		cin.getline(s1, 50);
		cout << "string 2? ";
		cin.getline(s2, 50);
		if(strcmp(s1,s2) == 0)
		{
			cout << "They are the same" << endl;
		}
		else if (strcmp(s1,s2) > 0)
		{
			cout << s1 << " is greater than " << s2 << endl;
		}
		else if (strcmp(s1,s2) < 0)
		{
			cout << s1 << " is less than " << s2 << endl; 
		} */

		return 0;
}