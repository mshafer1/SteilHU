// // this is a comment
/*
	this is a multi 
	line comment
*/
// any line that starts with # is an instruction to the compiler
#include<iostream>

using namespace std;

//start terminal 
void main()
{
	//cout - console output stream
	// << - stream insertion operator
	// literal - not a variable 
	cout << "Hello World" << endl;
	int i; //variable declaration
	int x = 9; // variable declaration and initialization
	i = 99; //initialization
	i = 88; //assignment
	// >> stream extraction operator
	//skips leading white space
	//stops at white space
	//cin >> i;
	//cin >> x;
	cin >> i >> x;
	cout << i << " " << x;

	system("Pause");
}
//end terminal 
