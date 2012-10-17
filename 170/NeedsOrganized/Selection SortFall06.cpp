#include <iostream>
#include <math.h>

using namespace std;

const int SIZE = 15;

void displayList(int list[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << list[i] << endl;
	}
}

bool isSorted(int list[])
{
	bool sorted = true;

	for(int i = 0; i < (SIZE - 1); i++)
	{
		if(list[i] > list[i+1])
		{
			sorted = false;
			break;
		}
	}

	return sorted;
}


void main()
{
	int list[SIZE] = {55,33,243,3245,67,34615,23,645436,523,424,56,3245,2345,324652,45};
	int smallest = 0;

	for(int k = 0; k <= SIZE - 2 && !isSorted(list); k++)
	{
		smallest = k;
		for(int i = k; i <= SIZE - 1; i++)
		{
			if( list[i] < list[smallest])
			{
				smallest = i;
			}
		}
		
		swap(list[k], list[smallest]);

	}

	displayList(list);
}


