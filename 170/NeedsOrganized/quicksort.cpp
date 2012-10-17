#include<iostream>
using namespace std;

void quickSort(int a[], int size)
{
	int pivot = a[0];
	int* left = new int[size-1]; //int left[size-1]
	int* right = new int[size-1]; //int right[size-1]
	int leftIndex = 0;
	int rightIndex = 0;

	for(int i = 1; i < size; i++)
	{
		if(a[i] < pivot)
		{
			left[leftIndex] = a[i];
			leftIndex++;
		}
		else
		{
			right[rightIndex] = a[i];
			rightIndex++;
		}
	}
	if(leftIndex > 1)
	{
		quickSort(left,leftIndex);
	}
	if(rightIndex > 1)
	{
		quickSort(right,rightIndex);
	}

	int j = 0;
	//add left bucket
	for(int li = 0; li < leftIndex;li++)
	{
		a[j] = left[li];
		j++;
	}
	//add pivot
	a[j] = pivot;
	j++;
	//add right bucket
	for(int ri = 0; ri < rightIndex;ri++)
	{
		a[j] = right[ri];
		j++;
	}


}

void main()
{
	int A[] = {123,341254,124234,23,2,46,45,45,63,6,6,1,256,345,34,456,43,6345};
	quickSort(A,18);

}