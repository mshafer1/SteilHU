// This program uses the selection sort algorithm to 
// sort an array of integers.
//
// Selection Sort Algorithm Description
//
//	1. Repeat steps 2 and 3 as index k goes from 0 to SIZE - 1. 
//	2. Find the smallest array value in the index range k to 
//		SIZE.  Assume it is found at index smallest. 
//	3. Swap the old value at position k with the value at smallest. 
//
// Author:  Dana Steil

#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

const int SIZE = 10;

void swap(int& x, int& y)
{
	int Temp = x;
	x = y;
	y = Temp;
}

void printList(int A[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(3) << A[i];
	}
	cout << endl << "press enter." << endl;
	cin.get();
	
}

int main()
{
	int A[] = {10, 9, 8, 7, 1, 2, 6, 3, 5, 4};

	int smallest;

	cout << endl << SIZE << " elements to sort: " << endl;
	printList(A);

	for(int k =0; k < SIZE - 1; k++)
	{
		smallest = k;

		for(int i = k+1; i < SIZE; i++)
		{
			if (A[i] < A[smallest])
			{
				smallest = i;
			}
		}
		swap(A[smallest],A[k]);
		
		cout << endl << k + 1 << " elements sorted.\n";
		printList(A);
	}
	
	cout << "Notice that the last (10th) element is already sorted." << endl << "press enter.";
	cin.get();

	return 0;
}
