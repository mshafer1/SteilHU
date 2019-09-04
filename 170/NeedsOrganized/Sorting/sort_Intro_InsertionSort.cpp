//This program uses the insertion sort algorithm to 
//sort an array of integers.
//
//Insertion Sort Algorithm Description
//This partitions the array in two parts sorted and unsorted.  

//  1.	Start with the element at index 0 in the sorted portion 
//  	    and the rest of the array in the unsorted portion. 
//	        Set DividerIndex to 1. 

//  2.	Repeat steps 3-7 as DividerIndex goes from 1 to SIZE-1. 

//  3.	Copy the value at the divider index in to another 
//          variable (DividerValue). 

//  4.	Search through the sorted portion until the DividerValue 
//	        is greater than a given element. 

//  5.	Move the rest of the element in the sorted region to the 
//	        right one position to make room for the DividerValue. 
//	        (There may not be any to move.)
 
//  6.	Place DividerValue in the position left open. 

//  7.	Increment the DividerIndex. 

#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void RandomlyFillList(long List[], int Length)
{
	for(int i = 0; i < Length; i++)
	{
		List[i] = rand()%100;
	}
}

void DisplayList(long List[], int Length)
{
	cout << '{';
	for(int i = 0; i < Length; i++)
	{
		cout << setw(3) << List[i];
	}
	cout << '}' << " Press enter.";
	cin.get();
}


int main()
{
	srand((unsigned int)time(0));

	const int LENGTH = 15;

	long List[LENGTH];

	RandomlyFillList(List,LENGTH);
	cout << "\nUnsorted  ";
	DisplayList(List,LENGTH);

	bool Sorted = false;

	long DividerValue;

	for(long DividerIndex = 1; DividerIndex <= LENGTH-1;)
	{   //step 1, step 2
		
		DividerValue = List[DividerIndex];
            //step 3
		int PositionToInsert;
		
		for(PositionToInsert = 0; 
			PositionToInsert < DividerIndex && DividerValue > List[PositionToInsert]; 
			PositionToInsert++);
			//step 4

		for(int i = DividerIndex; i > PositionToInsert; i--)
		{
			List[i] = List[i-1];
			//step 5
		}

		List[PositionToInsert] = DividerValue;
		    //step 6
		    
		DividerIndex++;
		    //step 7
		
		cout << "Sorting...";   
		DisplayList(List,LENGTH);	
	}
	cout << "Sorted    ";
	DisplayList(List,LENGTH);
	
	cout << "\nPress any key to exit.";
	cin.get();
	return 0;
}
