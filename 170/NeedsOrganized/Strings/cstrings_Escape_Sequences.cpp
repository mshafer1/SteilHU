#include<iostream>

using std::cout;
using std::cin;

//	Escape Sequences:
//	   	-type \" for "
//	   	-type \\ for \
// 		-type \n for carriage return
// 		-type \0 for null terminator
// 		-type \a to make the computer beep
int main()
{
	char c[] = "look at the \"qoutes\" and the \\slash\\. Start new line.\n Beep.\a Null terminator added\0";
	cout << c;
	cin.get();
	return 0;
}