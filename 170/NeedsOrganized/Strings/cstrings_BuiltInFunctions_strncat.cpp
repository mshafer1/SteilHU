//this program uses strncat() to concatenate, or append, one string to another

	// strcat(char a[], char b[], int n) strncat takes the first n character of c-style string
	//		b and adds them, and a null terminator, to the end of c-style string a. 
	
	//The function returns a.
	
	// note the 'n': think "number"

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	
	char s1[17] = "McDonalds "; //[17] because we need to make room for what we will add
	char s2[] = "Burger King";
	cout << strncat(s1, s2, 6);

	//when you use strcat and strncat, always make sure you have room in your array
	return 0;
}