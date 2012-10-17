//insertion sort
//Dana Steil
//Fall 2006
#include <iostream>
#include <math.h>

using namespace std;
const int SIZE = 10;

void displayList(int list[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << list[i] << endl;
	}
}

void main()
{
	int list[SIZE] = {22,33,12,3245,67,234,23,2,455,234};


	int dividerValue;

	for(int dividerIndex = 1; dividerIndex < SIZE; dividerIndex++ )
	{
		dividerValue = list[dividerIndex];

		//find the insertion point in the sorted portion of the list for the divider value
		int newSpotForDividerValue = 0;
		while( newSpotForDividerValue < dividerIndex && 
			  dividerValue > list[newSpotForDividerValue])
		{
			newSpotForDividerValue++;
		}

		//move all values between the new spot and the dividerindex to the right
		for(int i = dividerIndex - 1; i >= newSpotForDividerValue; i-- )
		{
			list[i+1] = list[i];
		}

		list[newSpotForDividerValue] = dividerValue;
	}

	displayList(list);
}