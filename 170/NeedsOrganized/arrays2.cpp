#include<iostream>
using namespace std;

const int MAX_GRADES = 500;

void getGradesToEnter( int& GradesToEnter )
{
	do
	{
		cout << "How many grades do you want to enter? "; 
		cin >> GradesToEnter;
	}
	while(GradesToEnter > MAX_GRADES);
}

void getGrades( int GradesToEnter, int Grades[] )
{
	for( int i = 0; i < GradesToEnter; i++ )
	{
		cout << "Grade " << i + 1 << "?";
		cin >> Grades[i];
	}
}

void displayGrades( int GradesToEnter, const int Grades[] )
{
	for( int i = 0; i < GradesToEnter; i++ )
	{
		cout << "Grade " << i + 1 << " is " << Grades[i] << endl;
	}
}

void copyGrades( const int From[], int To[], int gradesToCopy )
{
	for( int i = 0; i < gradesToCopy; i++ )
	{
		To[i] = From[i];
	}	
}


void main()
{
	//array - list of variables
	// they all must be of the same datatype
	int Grades[MAX_GRADES] = {0}; // 100 integers - indexes 0-99
	int Grades2[MAX_GRADES] = {0}; // 100 integers - indexes 0-99
	int GradesToEnter = 0;

	getGradesToEnter( GradesToEnter );
	getGrades( GradesToEnter, Grades );
	displayGrades( GradesToEnter, Grades ); 
	
	copyGrades(Grades, Grades2, GradesToEnter); // Grades2 = Grades;

}








