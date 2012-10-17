#include<iostream>
using namespace std;

bool same(const char s1[], const char s2[])
{
	bool result = true;

	int i = -1;
	do
	{
		i++;
		if( s1[i] != s2[i])
		{
			result = false;
		}
	}
	while( s1[i] != '\0' );

	return result;
}

void main()
{
	char s[100];
	char s2[100];

	cin >> s;
	cin >> s2;

	if(same(s2,s))
	{
		cout << "They are the same strings\n";
	}
}








