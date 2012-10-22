#include<iostream>
using namespace std;

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

void main()
{
	char s[100];
	char c;

	cin >> s;
	cin >> c;

	if(containsChar(s,c))
	{
		cout << "Yes " << s << " contains a(n) " << c << endl;
	}
}
















