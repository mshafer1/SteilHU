#include<iostream>
using namespace std;

void main()
{
	char source[100];
	char destination[100];
	cin.getline(source,100);
	//copies from the second argument to the first
	strcpy_s(destination, source);
	cout << destination << endl;
}
