#include<iostream>
using namespace std;

float HighestGrade(float Grades[], int GradesInList);
float LowestGrade(float Grades[], int GradesInList);
float AverageGrade(float Grades[], int GradesInList);
void GetGrades(float Grades[], int GradesInList);
void SortGrades(float Grades[], int GradesInList);

void main()
{
	const int GRADES_IN_LIST = 10;

	float Grades[GRADES_IN_LIST];
											//If there are fewer initializers 
	GetGrades(Grades, GRADES_IN_LIST);
	
	cout << "The hightest grade is " << HighestGrade(Grades, GRADES_IN_LIST) << endl;
	cout << "The lowest grade is " << LowestGrade(Grades, GRADES_IN_LIST) << endl;
	cout << "The Average Grade is " << AverageGrade(Grades, GRADES_IN_LIST) << endl;

	SortGrades(Grades,GRADES_IN_LIST);

}

float HighestGrade(float Grades[], int GradesInList)
{
	float HighestGradeFound = 0;

	for (int CurrentGrade = 0; CurrentGrade < GradesInList; CurrentGrade++)
	{
		if (HighestGradeFound < Grades[CurrentGrade])
		{
			HighestGradeFound = Grades[CurrentGrade];
		}
	}

	return HighestGradeFound;
}

float LowestGrade(float Grades[], int GradesInList)
{
	float LowestGradeFound;

	if (GradesInList > 0) 
	{
		LowestGradeFound = Grades[0];
	}

	for (int CurrentGrade = 0; CurrentGrade < GradesInList; CurrentGrade++)
	{
		if (LowestGradeFound > Grades[CurrentGrade])
		{
			LowestGradeFound = Grades[CurrentGrade];
		}
	}

	return LowestGradeFound;
}

float AverageGrade(float Grades[], int GradesInList)
{
	float TotalGrades = 0;

	for (int CurrentGrade = 0; CurrentGrade < GradesInList; CurrentGrade++)
	{
		TotalGrades = TotalGrades + Grades[CurrentGrade];
	}

	return TotalGrades/GradesInList;
}

void GetGrades(float Grades[], int GradesInList)
{
	for (int CurrentGrade = 0; CurrentGrade < GradesInList; CurrentGrade++)
	{
		cout << "Please enter grade " << CurrentGrade + 1 << " of " << GradesInList << ": ";
		cin >> Grades[CurrentGrade];
	}
}



void SortGrades(float Grades[], int GradesInList)
{
	int LowestGradeIndex;
	float temp;

	for (int CurrentGrade = 0; CurrentGrade < GradesInList; CurrentGrade++)
	{
		LowestGradeIndex = CurrentGrade;

		for (int i = CurrentGrade; i < GradesInList; i++) 
		{
			if (Grades[LowestGradeIndex] > Grades[i])
			{
				LowestGradeIndex = i;
			}
		}

		temp = Grades[LowestGradeIndex];
		Grades[LowestGradeIndex] = Grades[CurrentGrade];
		Grades[CurrentGrade] = temp;
	}

}