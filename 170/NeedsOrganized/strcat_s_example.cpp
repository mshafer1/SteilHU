#include<iostream>
using namespace std;

void main()
{
	char source[100];
	char destination[100];
	cin.getline(source,100);
	cin.getline(destination,100);
	//appends the source to the destination, no bounds checking
	strcat_s(destination, source);
	cout << destination << endl;
}
