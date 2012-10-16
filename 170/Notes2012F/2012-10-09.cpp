#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void SelectionSort(int A[], int length)
{
	for(int i = 0; i < length-1;i++)
	{
		int indexOfLargest = 0;
		for(int j = 1; j < length - i; j++)
		{
			if(A[j] > A[indexOfLargest])
			{
				indexOfLargest = j;
			}
		}
		int indexOfEnd = length - 1 - i;
		int temp = A[indexOfLargest];
		A[indexOfLargest] = A[indexOfEnd];
		A[indexOfEnd] = temp;

	}
}

void DisplayList(int A[], int length)
{
	for(int i = 0; i < length;i++)
	{
		cout << A[i] << endl;
	}
}

void main()
{
	srand(time(NULL));
	int A[100];
	for(int i = 0; i < 100;i++)
	{
		//A[i] = i;
		A[i] = rand()%1000;
	}
	//A[99] = -1;
	SelectionSort(A,100);
	DisplayList(A,100);
}