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

void reverse( char s[] )
{
	int l = length(s);
	for(int i = 0; i < l/2; i++)
	{
		//swap chars
		char temp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = temp;
	}
}


void main()
{
	char s[100];
	cin >> s;
	reverse(s);
	cout << s;
}