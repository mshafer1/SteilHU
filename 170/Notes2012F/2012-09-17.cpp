#include <iostream>
 
using namespace std;
 
void displayNumbers(float f[], int count)
{
	for(int i = 0; i < count; i++)
	{
		cout << f[i] << ", ";
	}
	cout << endl;
}

void displayNumbers2(float f[], int count)
{
	for(int i = 0; i < count; i++)
	{
		cout << *(f+i) << ", ";
	}
	cout << endl;
}

void displayNumbers3(float f[], int count)
{
	// p is a pointer to a float
	float* p = f;
	//walking a pointer
	while(p < (f + count))
	{
		p[0] = 1;
		cout << *p << ", ";
		p++;
	}
	cout << endl;
}

void main()
{
	float x[3];
	float numbers[] = {1.4,4.7,5.6};
	displayNumbers(numbers,3);
	displayNumbers2(numbers,3);
	displayNumbers3(numbers,3);
	//* value at an address
	//* is the dereference operator
	cout << *numbers << endl;
	cout << numbers[0] << endl;

	//pointer arithmetic
	cout << *(numbers + 1) << endl;
	cout << numbers[1] << endl;

	//float y[];
	system("Pause");
}

