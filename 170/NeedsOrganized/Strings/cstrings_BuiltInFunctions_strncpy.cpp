//this program uses the strncpy() function to copy contents of one c-style string to another

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	char s1[10] = "McDonalds";
	char s2[] = "Burger King"; 	//remember, when intializing and declaring a 
								//1D array at once, you don't need the n in [n]

	strncpy(s1,s2,5); //strncpy() copies the first n letters of s2 over s1

	cout << s1 << endl; //what do you think it will output?
	
	cin.get();
	return 0;
}
