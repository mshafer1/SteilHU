#include<iostream>
using namespace std;

int length(const char s[])
{
	int length = 0;

	while(s[length] != '\0')
	{
		length++;
	}
	return length;
}

void copy( char destination[], const char source[] )
{
	int i;
	for(i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

void copy2( char destination[], const char source[] )
{
	int i;
	for(i = 0; i < length(source); i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}


void main()
{
	char s[100];
	char s2[100];
	cin >> s;
	copy(s2,s);
	//copy2(s2,s);
	cout << s2;
}








