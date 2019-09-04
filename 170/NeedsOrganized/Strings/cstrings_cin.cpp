//this program shows how cin is used with c-style strings
//this program also practices flushing the buffer

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	
	char name[10];

	//cin >> ignores all leading white space
	//stops at white space (leaves it in the buffer)
	
	//	Using cin >> with c-style strings relies on the user to not
	//		put too many characters into your string. Make sure that
	// 		you do not go out of bounds by putting more characters in
	//		your array than you originally declared (no more than 10,in
	//		this case).
	
	cout << "Enter your first name (no more than 10 characters): ";
	cin >> name;
	cin.ignore(); 	//this drops 1 character from the buffer. In this case,
					// we assume it to be the carriage return character left by cin >>
					
					//note that cin >> stops at whitespace, including spaces.
					//	if you enter "Dana Steil" as input, "Dana" is stored in name,
					//	cin.ignore() drops the ' ', and Steil is left unflushed. This
					//		cin.ignore(100) drops up to 100 characters from the stream

	int age;
	cout << "Enter your age: ";
	cin >> age;
	cin.ignore(); //drop the carriage return again
	cout << endl << "Name: " << name << endl << "Age: " << age;
	
	cin.get(); 	//wait for a key to exit. If we did not flush the buffers with ignore(), 
				//	then this would be filled by whatever is still in the buffer.
	return 0;
}
