#include <iostream>
using namespace std;

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

void main()
{
	const int ITEMS = 7;

	int TestArray[ITEMS] = {10, 5, 3 , 2, 17 ,9 , 14};

	BubbleSort(TestArray,ITEMS);

	for (int i = 0; i < ITEMS; i++)
	{
		cout << TestArray[i] << " ";
	}
}







