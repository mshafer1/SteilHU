//counting Sort
//Dana Steil
//Fall 2006

#include <iostream>
using namespace std;

const int SIZE = 100000;

void displayList(int list[])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < list[i]; j++ )
		{
			cout << i << endl;
		}
	}
}

void main()
{
	int list[SIZE] = {0};
	int newValue;

	do
	{
		cout << "enter number:";
		cin >> newValue;
		if(newValue >= 0 && newValue <= SIZE - 1)
		{
			list[newValue]++;
		}
	
	}
	while(newValue >= 0 );

	displayList( list );
}
