#include<iostream>
using namespace std;

const int BAD_INDEX = -1;

int indexOfChar( const char s[], char c )
{
	int result = BAD_INDEX;

	for(int i = 0; s[i] != '\0' && result == BAD_INDEX; i++)
	{
		if( s[i] == c )
		{
			result = i;
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

	int index = indexOfChar(s,c);
	if(index != BAD_INDEX)
	{
		cout << s << " contains a(n) " << c 
			 << " at index " << index << endl;
	}
}
















