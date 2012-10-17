#include<iostream>
using namespace std;

void getLine(char s[], int size)
{
	int i = 0;

	do
	{
		s[i] = cin.get();
		i++;
	}
	while(s[i-1] != '\n' && i < size);

	s[i-1] = '\0';
}

void main()
{
	char s[10];
	getLine(s, 10);
	cout << s << endl;
}








