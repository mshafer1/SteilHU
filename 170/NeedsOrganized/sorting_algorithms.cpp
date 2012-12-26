//Lab 8 
//10/24/2001
//Put your name here
//Put your class time here

//Complete the implementations of the 
//SelectionSort and BubbleSort Functions

#include<iostream.h>
#include<time.h>
#include<stdlib.h>

void TestSelectionSort();
void TestSelectionSort2();
void TestBubbleSort();
void TestInsertionSort();

void SelectionSort(long A[], long Size);
void SelectionSort2(long A[], long Size);
void BubbleSort(long A[], long Size);
void InsertionSort(long A[], long Size);

void Show(long A[], long Size);
inline void Swap(long& a, long& b);
inline void FillWithRandomValues(long A[], long Size);

const long MAX_ELEMENTS = 100000;
const long TIMES_TO_TEST = 1;

void main()
{
	srand(time(NULL));

	TestSelectionSort();
	TestSelectionSort2();
	TestBubbleSort();
	TestInsertionSort();
}

void SelectionSort(long A[], long Size)
{
	for(long k = 0; k < Size - 1; k++)
	{
		long SmallestIndex = k;
		for(long i = k + 1; i < Size; i++)
		{
			if(A[i] < A[SmallestIndex])
			{
				SmallestIndex = i;
			}
		}

		long temp = A[k];
		A[k] = A[SmallestIndex];
		A[SmallestIndex] =temp;
	}
}

void SelectionSort2(long A[], long Size)
{
	for(long k = Size - 1; k >= 0; k--)
	{
		long LargestIndex = 0;
		for(long i = 1; i <= k; i++)
		{
			if(A[i] > A[LargestIndex])
			{
				LargestIndex = i;
			}
		}

		long temp = A[k];
		A[k] = A[LargestIndex];
		A[LargestIndex] = temp;
	}
}

void BubbleSort(long A[], long Size)
{
	bool Sorted = false;

	for(long i = 0; i < Size && !Sorted; i++)
	{
		Sorted = true;

		for(long k = 0; k < Size - i - 1; k++)
		{
			if(A[k] > A[k+1])
			{
				long temp = A[k];
				A[k] = A[k+1];
				A[k+1] = temp;
				
				Sorted = false;
			}
		}
	}
}

void InsertionSort(long A[], long Size)
{
	long DividerValue;
	long NewIndexForDividerValue;

	for(long DividerIndex = 1; DividerIndex < Size; DividerIndex++)
	{
		DividerValue = A[DividerIndex];

		for (NewIndexForDividerValue = 0; 
			A[NewIndexForDividerValue] < DividerValue; 
			NewIndexForDividerValue++);

		for(long i = DividerIndex; i > NewIndexForDividerValue; i--)
		{
			A[i] = A[i-1];
		}

		A[NewIndexForDividerValue] = DividerValue;
	}
}


inline void Swap(long& a, long& b)
{
	long temp = a;
	a = b;
	b = temp;
}

void Show(long A[], long Size)
{
	for(long i = 0; i < Size; i++)
	{
		cout << A[i] << ",";
	}

	cout << endl;
}

void FillWithRandomValues(long A[], long Size)
{
	for (long i = 0; i < Size; i++)
	{
		A[i] = rand();
	}
}

void TestSelectionSort()
{
	long A[MAX_ELEMENTS];

	double StartTime = clock();
	
	for (long i = 0; i< TIMES_TO_TEST; i++)
	{
		FillWithRandomValues(A, MAX_ELEMENTS);
		SelectionSort(A,MAX_ELEMENTS);	
	}
	
	double StopTime  = clock();

	cout << "SelectionSort = " << StopTime - StartTime << endl;
}

void TestSelectionSort2()
{
	long A[MAX_ELEMENTS];

	double StartTime = clock();
	
	for (long i = 0; i< TIMES_TO_TEST; i++)
	{
		FillWithRandomValues(A, MAX_ELEMENTS);
		SelectionSort2(A,MAX_ELEMENTS);	
	}
	
	double StopTime  = clock();

	cout << "SelectionSort2 = " << StopTime - StartTime << endl;
}

void TestBubbleSort()
{
	long A[MAX_ELEMENTS];

	double StartTime = clock();
	
	for (long i = 0; i< TIMES_TO_TEST; i++)
	{
		FillWithRandomValues(A, MAX_ELEMENTS);
		BubbleSort(A,MAX_ELEMENTS);	
	}
	
	double StopTime  = clock();

	cout << "Bubble = " << StopTime - StartTime << endl;
}

void TestInsertionSort()
{
	long A[MAX_ELEMENTS];

	double StartTime = clock();
	
	for (long i = 0; i< TIMES_TO_TEST; i++)
	{
		FillWithRandomValues(A, MAX_ELEMENTS);
		InsertionSort(A,MAX_ELEMENTS);	
	}
	
	double StopTime  = clock();

	cout << "InsertionSort = " << StopTime - StartTime << endl;
}
