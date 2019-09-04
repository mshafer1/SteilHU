//this program uses the strcpy() function to copy one c-style string into another

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	char s1[50];
	char s2[50];
	
	cout << "Enter a string: ";
	cin.getline(s1,50);

	//"s2 = s1" does not copy c-style strings
	strcpy(s2,s1);

	cout << "copy of string: ";
	cout << s2 << endl;
	
	cin.get();
	return 0;
}
