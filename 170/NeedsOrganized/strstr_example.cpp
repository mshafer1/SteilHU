#include<iostream>
using namespace std;

void main()
{
	char s1[100];
	cin.getline(s1,100);

	//strstr returns the address of the first occurance of a given string
	//returns NULL if the character is not found
	if( strstr(s1, "bob") != NULL )
	{
		cout << "it is in there" << endl;
		int index = (int)(strstr(s1, "bob") - s1);
		cout << index << endl;
	
	}
}


