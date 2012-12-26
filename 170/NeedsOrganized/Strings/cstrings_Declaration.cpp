//this program demonstrates different ways of declaring c-style strings.
	//discussion of char pointers and cout

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//array of integers
	int i[] = {0,1,2};
	cout << i << endl;
	
	//notice that i is a pointer, and the address that i points to 
	//	is displayed here. C++ makes a special case for 
	//	the char data type and cout. A char pointer inserted into
	//	the cout stream results in displaying all subsequent chars
	//	until a null terminator (int value of 0, ascii value of '\0')
	//	is encountered. 

	//array of characters
	char j[] = {'E','L','I'};
		//no null terminator, not a c-style string.
	//cout << j << endl;
		//there may or may not be an incidental null terminator in memory.
		//do NOT cout this. This will go out of bounds, even though it may
		//appear to work fine.

	//c-style string 
	char x[] = {'E','L','I','\0'};
		//even though '\0' is the same as 0, use '\0' for clarity
	cout << x << endl;

	//c-style string
	char e[] = "ELI";
	cout << e << endl;
	
	char b[100] = {'\0'}; //sets everything to zero. Empty string.
	
	
	//char e[];
		//does NOT work--the compiler does not know the array size.
	cin.get();
	return 0;
	
	//remember that none of these arrays can hold more data than the
	//	amount for which they have been declared.
}
