#include<iostream>
using namespace std;

float HighestGPA(float GPAS[], int GPASInList);
float LowestGPA(float GPAS[], int GPASInList);
float AverageGPA(float GPAS[], int GPASInList);
float MedianGPA(float GPAS[], int GPASInList);
void GetGPAS(float GPAS[], int GPASInList);
void SortGPAS(float GPAS[], int GPASInList);
void DisplayGPASFromLeastToGreatest(float GPAS[], int GPASInList);

void main()
{
	const int MAX_GPAS = 10;

	float GPAS[MAX_GPAS];
	
	int NumberOfGPAS;

	cout << "How many GPA's? ";
	cin >> NumberOfGPAS;
	
	GetGPAS(GPAS, NumberOfGPAS);
	SortGPAS(GPAS,NumberOfGPAS);

	cout << endl;

	DisplayGPASFromLeastToGreatest(GPAS,NumberOfGPAS);

	cout << endl;

	cout << "Maximum GPA  = " << HighestGPA(GPAS, NumberOfGPAS) << endl; 
	cout << "Minimum GPA =  " << LowestGPA(GPAS, NumberOfGPAS) << endl;
	cout << "Average GPA =  " << AverageGPA(GPAS, NumberOfGPAS) << endl;
	cout << "Median GPA = " << MedianGPA(GPAS, NumberOfGPAS) << endl;


}

float HighestGPA(float GPAS[], int GPASInList)
{
	float HighestGradeFound = 0;
	
	SortGPAS(GPAS,GPASInList);
	
	if (GPASInList > 0 )
	{
		HighestGradeFound = GPAS[GPASInList-1];
	}

	return HighestGradeFound;
}

float LowestGPA(float GPAS[], int GPASInList)
{
	float HighestGradeFound = 0;
	
	SortGPAS(GPAS,GPASInList);
	
	if (GPASInList > 0 )
	{
		HighestGradeFound = GPAS[0];
	}

	return HighestGradeFound;
}

float AverageGPA(float GPAS[], int GPASInList)
{
	float TotalGPAS = 0;

	for (int CurrentGrade = 0; CurrentGrade < GPASInList; CurrentGrade++)
	{
		TotalGPAS = TotalGPAS + GPAS[CurrentGrade];
	}

	return TotalGPAS/GPASInList;
}

float MedianGPA(float GPAS[], int GPASInList)
{
	float Median;

	SortGPAS(GPAS,GPASInList);

	if (GPASInList %2 == 0)
	{
		Median = (GPAS[GPASInList/2] + GPAS[(GPASInList/2)-1])/2;
	}
	else
	{
		Median = GPAS[(GPASInList-1)/2];
	}

	return Median;
}

void GetGPAS(float GPAS[], int GPASInList)
{
	for (int CurrentGrade = 0; CurrentGrade < GPASInList; CurrentGrade++)
	{
		cout << "GPA " << CurrentGrade + 1 << ": ";
		cin >> GPAS[CurrentGrade];
	}
}

void DisplayGPASFromLeastToGreatest(float GPAS[], int GPASInList)
{
	SortGPAS(GPAS, GPASInList);

	cout << "GPA's from least to greatest..." << endl;

	for (int CurrentGrade = 0; CurrentGrade < GPASInList; CurrentGrade++)
	{
		cout << GPAS[CurrentGrade] << endl;
	}
}

void SortGPAS(float GPAS[], int GPASInList)
{
	int LowestGradeIndex;
	float temp;

	for (int CurrentGrade = 0; CurrentGrade < GPASInList; CurrentGrade++)
	{
		LowestGradeIndex = CurrentGrade;

		for (int i = CurrentGrade; i < GPASInList; i++) 
		{
			if (GPAS[LowestGradeIndex] > GPAS[i])
			{
				LowestGradeIndex = i;
			}
		}

		temp = GPAS[LowestGradeIndex];
		GPAS[LowestGradeIndex] = GPAS[CurrentGrade];
		GPAS[CurrentGrade] = temp;
	}

}