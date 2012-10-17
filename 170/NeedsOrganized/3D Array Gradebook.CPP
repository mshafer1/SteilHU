#include<iostream>

using namespace std;

const int MAX_CLASSES = 100;
const int MAX_STUDENTS = 4;
const int MAX_ASSIGNMENT = 5;

void GetGrades(int GradeBook[][MAX_STUDENTS][MAX_ASSIGNMENT], int TotalClasses);
void ShowGrades(int GradeBook[][MAX_STUDENTS][MAX_ASSIGNMENT], int TotalClasses);

void main()
{

	int GradeBook [MAX_CLASSES][MAX_STUDENTS][MAX_ASSIGNMENT];

	GetGrades(GradeBook, 3);
	ShowGrades(GradeBook, 3);

}

void GetGrades(int GradeBook[][MAX_STUDENTS][MAX_ASSIGNMENT], int TotalClasses)
{
	for(int Class = 0; Class < TotalClasses; Class++)
	{
		for(int Student = 0; Student < MAX_STUDENTS; Student++)
		{
			for(int Assignment = 0; Assignment < MAX_ASSIGNMENT; Assignment++)
			{
				cout << "Please enter grade ";
				cin >> GradeBook[Class][Student][Assignment];
			}
		}
	}
}

void ShowGrades(int GradeBook[][MAX_STUDENTS][MAX_ASSIGNMENT], int TotalClasses)
{
	for(int Class = 0; Class < TotalClasses; Class++)
	{
		cout << "The Grades for class " << Class + 1 << "are"  << endl;

		for(int Student = 0; Student < MAX_STUDENTS; Student++)
		{
			for(int Assignment = 0; Assignment < MAX_ASSIGNMENT; Assignment++)
			{
				cout << GradeBook[Class][Student][Assignment] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

}