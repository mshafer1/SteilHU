#include<iostream>
#include<string>
#include<time.h>
using namespace std;


void BubbleSort(int A[], int length)
{
	int comparisons = 0;
	bool sorted = false;
	for(int i = 0; i < length-1 && !sorted;i++)
	{
		sorted = true;
		for(int j = 0; j < length-1-i;j++)
		{
			comparisons++;
			if(A[j] > A[j+1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				sorted = false;
			}
		}
	}
	cout << comparisons << " = comparisons" << endl;
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
	int A[100000];
	for(int i = 0; i < 100000;i++)
	{
		//A[i] = i;
		A[i] = rand()%1000;
	}
	//A[99] = -1;
	BubbleSort(A,100000);
	DisplayList(A,100);
}