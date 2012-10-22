#include<iostream>
using namespace std;

void getAge(int& age)
{
	do
	{
		cout << "Enter age: ";
		cin >> age;
	}
	while(age < 0 || age > 115);
}

void main()
{
	int age = 0;
	getAge(age);

	cout << "your age is " << age << endl;
}