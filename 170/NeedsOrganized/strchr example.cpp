#include<iostream>
using namespace std;

void main()
{
	char s1[100];
	cin.getline(s1,100);

	//strchr returns the address of the first occurance of a given char
	//returns NULL if the character is not found
	if( strchr(s1, 'a') != NULL )
	{
		cout << "it is in there" << endl;
		//subtract the base address from the address where there char was found
		int index = (int)strchr(s1, 'a') - (int)s1;
		cout << index << endl;	
	}
}


