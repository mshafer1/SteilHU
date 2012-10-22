#include<iostream>
using namespace std;

void main()
{
	char s[100];
	cin.getline(s,100);
	cout << s << endl;
	//strlen returns the length of the string as an integer
	cout << strlen(s);
}
