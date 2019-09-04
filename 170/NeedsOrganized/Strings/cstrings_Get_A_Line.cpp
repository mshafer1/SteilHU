//this program uses a function to retrieve a line of data from cin and
//	store it in a c-style string

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void getALine(char s[], int size)
{
	int i = 0;

	do
	{
		s[i] = cin.get(); //cin.get() returns 1 char from the stream
		i++;
	}
	while(s[i - 1] != '\n' && i < size);
		//loop until a carriage return is encountered, or until
		//	the string is full.

	s[i-1] = '\0';
}

int main()
{
	char s[100];
	cout << "type a line: ";
	getALine(s, 100);
	cout << "line: " << s << endl;
	
	cin.get();
	return 0;
}








