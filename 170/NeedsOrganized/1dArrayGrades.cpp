#include <iostream>
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

void main()
{
	int gradeCount;
	int grades[MAX_GRADES];

	getGrades( grades, gradeCount );
	displayGrades( grades, gradeCount );
}