#include<iostream>
using namespace std;

const int MAX_GRADES = 100;

void displayGrades( const int grades[], int gradeCount )
{
	for(int i = 0; i < gradeCount; i++)
	{
		cout << grades[i] << endl;
	}
}

void getGrades( int grades[], int& gradeCount )
{
	do
	{
		cout << "How many grades will you enter? ";
		cin >> gradeCount;
	}
	while(gradeCount < 0 || gradeCount > MAX_GRADES);

	for(int i = 0; i < gradeCount; i++)
	{
		cin >> grades[i];
	}
}

int gradeOccurances( int grades[], int gradeCount, int lowGrade, int highGrade  )
{
	int result = 0;

	for(int i = 0; i < gradeCount; i++)
	{
		if( grades[i] >= lowGrade && grades[i] <= highGrade )
		{
			result++;
		}
	}

	return result;
}

int gradeOccurances( int grades[], int gradeCount, int queryGrade )
{
	return gradeOccurances(grades, gradeCount, queryGrade, queryGrade) > 0;
}

bool hasGrade( int grades[], int gradeCount, int queryGrade )
{
	return (gradeOccurances(grades, gradeCount, 77 ) > 0);
}

bool hasGrade( int grades[], int gradeCount, char queryGrade )
{
	bool result = false;

	switch( toupper(queryGrade) )
	{
		case 'A':
			result = (gradeOccurances(grades,gradeCount, 90, 100) > 0);
			break;
		case 'B':
			result = (gradeOccurances(grades,gradeCount, 80, 89) > 0);
			break;
		case 'C':
			result = (gradeOccurances(grades,gradeCount, 70, 79) > 0);
			break;
		case 'D':
			result = (gradeOccurances(grades,gradeCount, 60, 69) > 0);
			break;
		case 'F':
			result = (gradeOccurances(grades,gradeCount, 0, 59) > 0);
			break;		
	}

	return result;
}


int main()
{
	int gradeCount;
	int grades[MAX_GRADES];

	getGrades( grades, gradeCount );
	displayGrades( grades, gradeCount );

	if( hasGrade(grades, gradeCount, 'b' ) )
	{
		cout << "Yes, there are " << endl;
	}

	return 0;
}