//This program uses the selection bubble algorithm to 
//sort an array of integers.
//
//Bubble Sort Algorithm Description
//1.	Repeat steps 2-6 as index i goes from 0 to SIZE – 1 
//	times or until you find that the array is sorted. 
//2.	Assume the array is sorted. 
//3.	Repeat steps 4-6 as index k goes from 0 to SIZE – 1 –  i. 
//4.	On each pass compare element at index k and element k + 1. 
//5.	If the pair is in increasing order (or the values 
//	are identical) leave the values as they are.  
//6.	If the pair is in decreasing order, swap them.  
//	Now you know that the array was not sorted. 


#include<iostream>
#include<time.h>

using namespace std;

const int SIZE = 17;

void InitializeList(int List[])
{
	for(int i = 0;i < SIZE; i++)
	{
		List[i] = rand() % SIZE;
	}
}

bool OneOfEach(int List[])
{
	bool Result = true;

	for(int i = 0; i < SIZE; i++)
	{
		if (List[i]!= i)
		{
			Result = false;
		}
	}

	return Result;
}

void main()
{
	srand(time(0));

	int List[SIZE];
	long Tries = 0;
	
	
	do
	{
		InitializeList(List);
		
		bool Sorted = false;
		//Repeat steps 2-6 as index i goes from 0 to SIZE – 2 times or 
		//until you find that the array is sorted. 
		
		for(int i = 0; i <= SIZE-2 && !Sorted;i++)
		{
			//Assume the array is sorted. 
			Sorted = true;

			//Repeat steps 4-6 as index k goes from 0 to SIZE – 2 –  i. 
			for(int k = 0; k <= SIZE - i - 2; k++)
			{
				//On each pass compare element at index k and element k + 1. 
				if(List[k] <= List[k+1])
				{
					//If the pair is in increasing order 
					//(or the values are identical) leave 
					//the values as they are.
				}
				else
				{
					//If the pair is in decreasing order, swap them.  
					//Now you know that the array was not sorted
					Sorted = false;
					
					int Temp;
					Temp = List[k];
					List[k] = List[k+1];
					List[k+1] = Temp;

				}
			}
		}
		Tries++;
	}
	while(! OneOfEach(List));

	for(int i = 0; i < SIZE; i++)
	{
		cout << List[i] << endl;
	}

	cout << "It took " << Tries << endl;
}





