//This program uses the selection sort algorithm to 
//sort an array of integers.
//
//Selection Sort Algorithm Description
//
//1.	Repeat steps 2 and 3 as index k goes from 0 to SIZE-2. 
//2.	Find the smallest array value in the index range k to 
//	SIZE – 1.  Assume it is found at index smallest. 
//3.	Swap the old value at position k with the value at smallest. 
//
//Author:  Dana Steil

#include<iostream>
#include<iomanip>

using namespace std;

void Swap(int& x, int& y)
{
	int Temp = x;
	x = y;
	y = Temp;
}

void PrintList(int A[], const int LIST_SIZE)
{
	for (int i = 0; i < LIST_SIZE; i++)
	{
		cout << setw(4) << A[i];
	}
	cout << endl;
}

void main()
{
	int A[] = {3,8,4,7,6};

	const int SIZE = 5;
	int Smallest;

	PrintList(A,SIZE);

	for(int k =0; k <= SIZE -2; k++)
	{
		Smallest = k;

		for(int i = k+1; i <= SIZE-1; i++)
		{
			if (A[i] < A[Smallest])
			{
				Smallest = i;
			}
		}
		Swap(A[Smallest],A[k]);
		PrintList(A,SIZE);
	}

}
