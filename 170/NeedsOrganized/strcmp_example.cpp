#include<iostream>
using namespace std;

void main()
{
	char s1[100];
	char s2[100];
	cin.getline(s1,100);
	cin.getline(s2,100);
	
	cout << strcmp(s1,s2) << endl;
	//compares two strings case sensitivly
	//returns 0 when they are the same
	//returns < 0 when s1 < s2
	//returns > 0 when s1 > s2
	if( strcmp(s1,s2) == 0 )
	{
		cout << "same strings" << endl;
	}
}


