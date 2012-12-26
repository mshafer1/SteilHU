//this program practices flushing the buffer

#include<iostream>

using namespace std;

int main()
{
	
	char name[10];
	cout << "Enter your name (no more than 10 characters): ";
	cin >> name;
	cin.ignore(); 	//this drops 1 character from the buffer. In this case,
					// we assume it to be the carriage return character left by 
					// cin >> (from when the user hit enter).
					
					//note that cin >> stops at whitespace, including spaces.
					//	if you enter "Dana Steil" as input in the code above, 
					//	"Dana" is stored in name, cin.ignore() drops the ' ', 
					//	and "Steil\n" is left unflushed.

	int age;
	cout << "Enter your age: ";
	cin >> age;
	cin.ignore(); //drops 1 character from the buffer
	
	char stuff[1000];
	cout << "Type some stuff, include spaces: ";
	cin >> stuff; //stores all characters until whitespace is encountered
	
	cin.ignore(1000, '\n'); 	// this drops up to 1000 characters until a
								// carriage return is found, which would be dropped as well.
	
	//this is useful because we know that when cin >> is used, there can only
	// 	be one carriage return per input, and it is always at the end.
	
	cout << endl << "Name: " << name << endl << "Age: " << age;
	
	
	
	cout << endl << "Press Enter.";
	cin.get(); 	//wait for a key to exit. If we did not flush the buffers with ignore(), 
				//	then this would be filled by whatever is still in the buffer.
				
				//if the program stops here and waits for you to press a key, then we have
				//	flushed the buffer correctly.
				
	//there are many ways to flush the buffer. Here we flushed it directly after 
	//	each input, but you can also flush it right before.
	return 0;
}