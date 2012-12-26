//this program uses the SELECTION SORT algorithm to sort an array of GPAs received from the user, and displays the sorted array.

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void GetGPAs(float arrayOfGPAs[], int GPAsInList);
void SortGPAs(float arrayOfGPAs[], int GPAsInList);

const int MAX_GPA_COUNT = 10;

int main()
{

	float arrayOfGPAs[MAX_GPA_COUNT]; // creating an array of floats
	
	int numberOfGPAs = 0;

	cout << "How many GPA's? ";
	
	do
	{
		cin >> numberOfGPAs;
		if(numberOfGPAs > MAX_GPA_COUNT)
		{
			cout << endl << "Please enter no more than " << MAX_GPA_COUNT << ": ";
		}
	}while(numberOfGPAs > MAX_GPA_COUNT); //input validation loop
	
	
	
	GetGPAs(arrayOfGPAs, numberOfGPAs);
	SortGPAs(arrayOfGPAs,numberOfGPAs);
	
	cout << endl << "GPA's from least to greatest..." << endl;

	for (int CurrentGrade = 0; CurrentGrade < numberOfGPAs; CurrentGrade++)
	{
		cout << arrayOfGPAs[CurrentGrade] << endl;
	}
	
	cin.get();
	
	return 0;

}
void GetGPAs(float arrayOfGPAs[], int GPAsInList)
{
	for (int CurrentGrade = 0; CurrentGrade < GPAsInList; CurrentGrade++)
	{
		cout << "GPA " << CurrentGrade + 1 << ": ";
		cin >> arrayOfGPAs[CurrentGrade];
	}
}

void SortGPAs(float arrayOfGPAs[], int GPAsInList) // "selection sort" algorithm
{
	int LowestGradeIndex;

	for (int CurrentGrade = 0; CurrentGrade < GPAsInList; CurrentGrade++)
	{
		LowestGradeIndex = CurrentGrade;	// arrayOfGPAs[currentGrade] will always be the first unsorted element.
											// All values behind arrayOfGPAs[currentGrade] are sorted.

		for (int i = CurrentGrade; i < GPAsInList; i++)			// This loop passes over the unsorted elements
		{														// and stores the index of the lowest among them.
			if (arrayOfGPAs[LowestGradeIndex] > arrayOfGPAs[i])
			{	
				LowestGradeIndex = i;	
			}		
		}

		float temp;
		temp = arrayOfGPAs[LowestGradeIndex]; 
		arrayOfGPAs[LowestGradeIndex] = arrayOfGPAs[CurrentGrade]; 	// these 4 lines of code swap the values of arrayOfGPAs[currentGrade] with
		arrayOfGPAs[CurrentGrade] = temp;							// the lowest unsorted element. arrayOfGPAs[currentGrade] now contains a sorted element, 
	} 																//thus currentGrade is ready to be incremented by the loop. 
	//notice that the sorting is done IN PLACE. In other words, no new arrays are created.
}