#include<iostream>
using namespace std;

// write a funtion named isSameString
//it should take two c-style string as arguments and then
//return true if they have the same characters, false otherwise

bool isSameString(char s1[], char s2[] )
{

}

int stringLength(char s[])
{
	int result = 0;

	while(s[result] != '\0')
	{
		result++;
	}

	return result;
}

void stringCopy(char destination[], char source[] )
{
	int i = 0;
	while(source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}



void main()
{
	if(isSameString("apple","orange"))
	{
		cout << "same";
	}
	else
	{
		cout << "different";
	}
	char s[100];
	char s2[100];

	cin >> s;
	//s2 = s;  // will not work
	stringCopy(s2, s);
	cout << s2;


	////cin >> s;
	////cin.getline vs cin >>
	////getline lets you get whitespace
	////bounds checking
	//cin.getline(s,10);
	////cin >> s;
	//cout << s << endl;
	//if(cin.fail())
	//{
	//	cout << "Failed" <<endl;
	//	cin.clear(); //clears the error flag
	//	cin.ignore(cin.rdbuf()->in_avail());
	//}
	//
	//cin.getline(s,100,'d');
	////cin >> s;
	//cout << s << endl;
}



