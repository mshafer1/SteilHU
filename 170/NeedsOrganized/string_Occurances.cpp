#include<iostream>
#include<stdlib.h>
using namespace std;

//this program accepts two strings as input
//it then displays how many of the second string appear in the first
void main()
{
	char s[100];
	char searchText[100];
	char* occurance = s; //occurance is a char pointer

	cout << "Enter the text in which you want to search: ";
	cin.getline(s,100);

	cout << "Enter the text you want to search for: ";
	cin.getline(searchTest,100);

	int occurances = 0;  
	occurance =  strstr(occurance, searchText);

	while( occurance != NULL )
	{
		cout << occurance << endl;
		occurances++;
		occurance =  strstr(occurance + 1, searchText);
	}

	cout << "There are " << occurances << " " << searchText << "'s in " << s << endl;

}


