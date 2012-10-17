#include<iostream>
#include<string>

using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_ASSIGNMENTS = 100;
const int MAX_NAME_LENGTH = 100;

void GetNames(char Names[][MAX_NAME_LENGTH], int Students)
{
	for(int i = 0; i < Students; i++)
	{
		cout << "Name " << i + 1 << ": ";
		cin.getline(Names[i],MAX_NAME_LENGTH);
	}
}

void DisplayName(char Name[])
{
	cout << Name << endl;
}

void DisplayNames(char Names[][MAX_NAME_LENGTH], int Students)
{
	for(int i = 0; i < Students; i++)
	{
		cout << "Name " << i + 1 << " is ";
		DisplayName(Names[i]);
	}
}


void GetGrades(float Grades[][MAX_ASSIGNMENTS], 
			   char Names[][MAX_NAME_LENGTH], 
			   int Students,
			   int Assignments)
{
	for(int Student = 0; Student < Students; Student++)
	{
		cout << "Grades for " << Names[Student] << endl;
		for(int Assignment = 0; Assignment < Assignments; Assignment++)
		{
			cout << "Assignment #" << Assignment + 1 << " ";
			cin >> Grades[Student][Assignment];
		}

	}
}

void DisplayGrades(float Grades[][MAX_ASSIGNMENTS], 
			   char Names[][MAX_NAME_LENGTH], 
			   int Students,
			   int Assignments)
{
	for(int Student = 0; Student < Students; Student++)
	{
		cout << "Grades for " << Names[Student] << endl;
		for(int Assignment = 0; Assignment < Assignments; Assignment++)
		{
			cout << "Assignment #" << Assignment + 1 << " ";
			cout << Grades[Student][Assignment] << endl;
		}

	}
}

void DisplayGradeAverages(float Grades[][MAX_ASSIGNMENTS], 
			   char Names[][MAX_NAME_LENGTH], 
			   int Students,
			   int Assignments)
{
	for(int Student = 0; Student < Students; Student++)
	{	
		float Total = 0;

		for(int Assignment = 0; Assignment < Assignments; Assignment++)
		{
			Total = Total + Grades[Student][Assignment];
		}
	
		cout << "Average for " << Names[Student] << " is ";
		cout << Total/Assignments << endl;

	}
}

void main()
{
	int Students;
	int Assignments;

	float Grades[MAX_STUDENTS][MAX_ASSIGNMENTS];
	char Names[MAX_STUDENTS][MAX_NAME_LENGTH];

	cout << "How many students do you have?";
	cin >> Students;

	cout << "How many assignments should they complete?";
	cin >> Assignments;
	
	getchar();//to throw away the end of line char

	GetNames(Names, Students);

	GetGrades(Grades, Names, Students,Assignments);
	DisplayGrades(Grades, Names, Students,Assignments);
	DisplayGradeAverages(Grades, Names, Students,Assignments);

	//DisplayNames(Names, Students);

	
	

}