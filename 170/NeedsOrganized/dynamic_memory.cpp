#include<iostream>

using namespace std;


//\0 is the char with an ASCII value of 0

void main()
{
	//dynamically create (alocate) a variable with "new"
	//dynamic vs. local

	int x = 7; //x is a local integer

	//NULL the address 0
	int* px = NULL; //px is a pointer to an integer
			//px contains the addess of an integer

	//& means the address of
	px = &x;

	cout << x << endl;
	cout << px << endl; //prints the address of x
	
	if(px != NULL)
	{
		cout << *px << endl; //prints what's at px
	}

	int* pint = NULL;

	pint = new int; //dynamically created

	cout << pint << endl;

	cout << *pint << endl;
	*pint = 10;
	cout << *pint << endl;


	int* pArray = NULL; // as opposed to int Array[10];

	cout << "Size?";
	cin >> x;

	pArray = new int[x];

	for(int i = 0; i < x; i++)
	{
		cin >> pArray[i];
		//cin >> *(pArray + i); 
	}

	for(int i = 0; i < x; i++)
	{
		cout << pArray[i] << endl;
	}

}








