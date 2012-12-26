
#include<iostream>
#include<time.h>

using namespace std;

const int SIZE = 70000;

void selectionSort( int a[] )
{
	for(int k = 0; k <= SIZE - 2; k++)
	{
		int indexOfSmallest = k;
		for(int i = k; i <= SIZE - 1; i++)
		{
			if(a[i] < a[indexOfSmallest])	
			{
				indexOfSmallest = i;
			}
		}
	
		int temp = a[k];
		a[k] = a[indexOfSmallest];
		a[indexOfSmallest] = temp;
	}
}

void bubbleSort( int a[] )
{
	bool sorted = false;
	for(int i = 0; i < SIZE && !sorted; i++)
	{
		sorted = true;
		for(int k = 0; k < SIZE -1 - i; k++ )
		{
			if(a[k] > a[k+1])
			{
				int temp = a[k];
				a[k] = a[k+1];
				a[k+1] = temp;
				sorted = false;
			}
		}
	}
}


void initializeList( int a[] )
{
	for(int j = 0; j < SIZE; j++)
	{
		a[j] = rand() % 1000;
	}
}

void main()
{
	int a[SIZE];
	srand( time(0));

	initializeList( a ); 
	time_t startTime = time(0);
	selectionSort( a );
	time_t stopTime = time(0);
	cout << "Selection sort took " << stopTime - startTime << endl;

	initializeList( a ); 
	startTime = time(0);
	bubbleSort( a );
	stopTime = time(0);
	cout << "Bubble sort took " << stopTime - startTime << endl;

}