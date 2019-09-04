//this program is a simple implementation of the bubble sort algorithm

#include <iostream>

using std::cout;
using std::cin;

//	Bubble Sort Algorithm Description
//
// 1.	Repeat steps 2-6 as index Passes goes from 0 to Items – 1 
//			times or until you find that the array is sorted. 
//
// 2.	Assume the array is sorted. 
//
// 3.	Repeat steps 4-6 as index Comparisons goes from 0 to 
//			Items – 1 –  i. 
//
// 4.	On each pass compare element at index Comparisons and element 
//			Comparisons + 1. 
//
// 5.	If the pair is in increasing order (or the values 
//			are identical) leave the values as they are.  
//
// 6.	If the pair is in decreasing order, swap them.  
//			Now you know that the array was not sorted. 

void BubbleSort ( int Array[], int Items)
{
	int Temp;

	for (int Passes = 0; Passes < Items - 1; Passes++)
	{
		for (int Comparisons = 0; Comparisons < Items - Passes - 1; Comparisons++)
		{
			if (Array[Comparisons] > Array[Comparisons + 1])
			{
				Temp = Array[Comparisons];
				Array[Comparisons] = Array[Comparisons + 1];
				Array[Comparisons + 1] = Temp;
			}
		}
	}
}

int main()
{
	const int ITEMS = 7;

	int TestArray[ITEMS] = {10, 5, 3 , 2, 17 ,9 , 14};

	BubbleSort(TestArray,ITEMS);

	for (int i = 0; i < ITEMS; i++)
	{
		cout << TestArray[i] << " ";
	}
	cout << "\nPress Enter.";
	cin.get();
	return 0;
}







