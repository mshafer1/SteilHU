//this program uses the '&' operator to make
//  parameters a reference to an outside variable,
//  rather than a copy.

#include<iostream>

using std::cout;
using std::cin;

void getAge(int& age)
{   // the '&' operator means this function can change the original
	do
	{
		cout << "Enter age: ";
		cin >> age;
		cin.ignore();
	}
	while(age <= 0 || age > 115); //input validation loop: invalid entries
}                                //     are not accepted

int main()
{
	int age = 0;
	getAge(age);
        //age is not 0 anymore
	cout << "your age is " << age;
	
    cin.get();
    return 0;
}
