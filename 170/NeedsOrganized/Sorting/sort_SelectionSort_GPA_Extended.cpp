//this program uses the SELECTION SORT algorithm to perform various perations a
	//float array of GPAs received from the user.

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

float HighestGPA(float arrayOfGPAs[], int GPAsInList);
float LowestGPA(float arrayOfGPAs[], int GPAsInList);
float AverageGPA(float arrayOfGPAs[], int GPAsInList);
float MedianGPA(float arrayOfGPAs[], int GPAsInList);
void GetGPAs(float arrayOfGPAs[], int GPAsInList);
void SortGPAs(float arrayOfGPAs[], int GPAsInList);
void DisplayGPAsFromLeastToGreatest(float arrayOfGPAs[], int GPAsInList);

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

	cout << endl;

	DisplayGPAsFromLeastToGreatest(arrayOfGPAs,numberOfGPAs);

	cout << endl;

	cout << "Maximum GPA  = " << HighestGPA(arrayOfGPAs, numberOfGPAs) << endl; 
	cout << "Minimum GPA =  " << LowestGPA(arrayOfGPAs, numberOfGPAs) << endl;
	cout << "Average GPA =  " << AverageGPA(arrayOfGPAs, numberOfGPAs) << endl;
	cout << "Median GPA = " << MedianGPA(arrayOfGPAs, numberOfGPAs) << endl;

	return 0;
}

float HighestGPA(float arrayOfGPAs[], int GPAsInList) 
{
	float HighestGradeFound = 0;
	
	SortGPAs(arrayOfGPAs,GPAsInList);
	
	if (GPAsInList > 0 )
	{
		HighestGradeFound = arrayOfGPAs[GPAsInList-1];
	}

	return HighestGradeFound;
}

float LowestGPA(float arrayOfGPAs[], int GPAsInList)
{
	float HighestGradeFound = 0;
	
	SortGPAs(arrayOfGPAs,GPAsInList);
	
	if (GPAsInList > 0 )
	{
		HighestGradeFound = arrayOfGPAs[0];
	}

	return HighestGradeFound;
}

float AverageGPA(float arrayOfGPAs[], int GPAsInList)
{
	float TotalGPAs = 0;

	for (int CurrentGrade = 0; CurrentGrade < GPAsInList; CurrentGrade++)
	{
		TotalGPAs = TotalGPAs + arrayOfGPAs[CurrentGrade];
	}

	return TotalGPAs/GPAsInList;
}

float MedianGPA(float arrayOfGPAs[], int GPAsInList)
{
	float Median;

	SortGPAs(arrayOfGPAs,GPAsInList);

	if (GPAsInList %2 == 0)
	{
		Median = (arrayOfGPAs[GPAsInList/2] + arrayOfGPAs[(GPAsInList/2)-1])/2;
	}
	else
	{
		Median = arrayOfGPAs[(GPAsInList-1)/2];
	}

	return Median;
}

void GetGPAs(float arrayOfGPAs[], int GPAsInList)
{
	for (int CurrentGrade = 0; CurrentGrade < GPAsInList; CurrentGrade++)
	{
		cout << "GPA " << CurrentGrade + 1 << ": ";
		cin >> arrayOfGPAs[CurrentGrade];
	}
}

void DisplayGPAsFromLeastToGreatest(float arrayOfGPAs[], int GPAsInList)
{
	SortGPAs(arrayOfGPAs, GPAsInList);

	cout << "GPA's from least to greatest..." << endl;

	for (int CurrentGrade = 0; CurrentGrade < GPAsInList; CurrentGrade++)
	{
		cout << arrayOfGPAs[CurrentGrade] << endl;
	}
}

void SortGPAs(float arrayOfGPAs[], int GPAsInList) // SELECTION SORT algorithm
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
	//note that this algorithm does its sorting IN PLACE. In other words, no new arrays are created.
}