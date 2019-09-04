//this program reverses the contents of a c-style string

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

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
		char temp = s[i]; //swap chars
		s[i] = s[l - i - 1];
		s[l - i - 1] = temp;
	}
}


int main()
{
	char s[100];
	cout << "String: ";
	cin >> s;
	cin.ignore();

	reverse(s);
	cout << "Reversed: " << s;
	
	cin.get();
	return 0;
}
