//this program uses the strchr() function to find a character in a string

	//strchr(char a[], char b) returns the pointer of the first instance of the character b in c-style string a.

#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	
	char cstring[50] = "Harding University";
	char character = '\0';
	
	cout << "C-style string: " << cstring << endl;
	
	cout << "Print \"University\": ";
	cout << strchr(cstring, 'U') << endl;
		//cout from U until null terminator
	
	int indexOfU = ((strchr(cstring, 'U')) - cstring); 
		//pointer minus a pointer
	cout << "Print the index of 'U': ";
	cout << indexOfU << endl;
	
	cout << "Print what is after 'U': ";
	cout << cstring[indexOfU + 1] << endl;		
	
	cin.get();
	return 0;
}