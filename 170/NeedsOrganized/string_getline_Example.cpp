#include<iostream>
using namespace std;

void GetLineExample()
{
	char s[20];
	char s2[20];

	//cin.get(s,20);
	//cin.get();

	//cin.get(s2,20);
	//cin.get();

	//Use getline to automaticaly remove the end of line
	//character from the input buffer.

	//getline like get will get white space and has bounds checking	
	cin.getline(s,20);
	cin.getline(s2,20);

	cout << s << endl;
	cout << s2 << endl;
}


void main()
{
	GetLineExample();
}