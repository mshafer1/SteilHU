#include<iostream>
#include<iomanip>

using namespace std;

void main()
{
	int x = 9;
	cout << x << endl;
	cout << &x << endl;

	int* p = &x;// p is a pointer to an integer, can hold the address of an int
	cout << p << endl;
	cout << *p << endl; //* means what's at

	int A[10]; // indexes 0-9 - 10 ints

	for(int i = 0; i < 10; i++)
	{
		A[i] = i * 5;
		//*(A + i) = i * 5;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}

	p = A;

	cout << endl;

	while( p < (A + 10))
	{
		cout << *p << " ";
		p++;
	}
}

