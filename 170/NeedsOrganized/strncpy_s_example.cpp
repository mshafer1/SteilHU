#include<iostream>
using namespace std;

void main()
{
	char source[100];
	char destination[100];
	cin.getline(source,100);
	cin.getline(destination,100);
	//copies n characters from the second argument to the first 
	//does not place a null terminator at the end of the destination
	strncpy_s(destination, source, 3);
	//destination[3] = '\0';
	cout << destination << endl;
}
