#include<iostream>
#include<stdlib.h>
using namespace std;

//The goal of this program is to accept a persons name as input in the form first last
//then modify the string it is stored in to contain last, first
void main()
{
	char name[100];
	cin.getline(name,100);

	//make pSpace point to the first space in name (it will be NULL if one is not found)
	char* pSpace = strchr(name, ' ');

	if( pSpace != NULL)
	{
		//replace the space with the null terminator
		*pSpace = '\0';
		strcat( pSpace + 1, ", ");
		strcat( pSpace + 1, name);
		strcpy( name, pSpace + 1 );
		cout << name << endl;
	}
}

