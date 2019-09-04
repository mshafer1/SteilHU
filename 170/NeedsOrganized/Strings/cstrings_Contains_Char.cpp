//this program looks for a character within a string, without using the built-in functions

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

bool containsChar( const char s[], char c )
{
	bool result = false;

	for(int i = 0; s[i] != '\0' && !result; i++)
	{
		if( s[i] == c )
		{
			result = true;
		}
	}

	return result;
}

int main()
{
	char s[50];
	char c;

	cout << "String: ";
	cin.get(s, 50); //get up to 50 chars, store in s1
	cin.ignore(); //ignore the carriage return
	
	cout << "Character: ";
	cin.get(c);
	cin.ignore();

	if(containsChar(s,c))
	{
		cout << "Yes, " << s << " contains '" << c << '\'' << endl;
	}
	else
	{
		cout << "No, " << s << " does not contain '" << c << '\'' << endl;
	}
	
	cin.get();
	return 0;
}
















