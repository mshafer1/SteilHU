#include<iostream>
using namespace std;

void main()
{
	char source[100];
	char destination[100];
	cin.getline(destination,100);
	cin.getline(source,100);
	//appends the first n characters of the source to the destination 
	//no bounds checking
	strncat_s(destination, source,3);
	cout << destination << endl;
}
