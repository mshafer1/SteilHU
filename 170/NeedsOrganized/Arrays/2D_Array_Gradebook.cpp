//this program receives multiple grades for multiple students, stores them in a 2D array,
	// and then displays a student's grade average

#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;

const int MAX_STUDENTS = 100;
const int MAX_ASSIGNMENTS = 50;

void getGrades(int assignments, int students, double gradeBook[][MAX_ASSIGNMENTS])
{
	for(int assignment = 0; assignment < assignments; assignment++)
	{
		for(int student = 0; student < students; student++)
		{
			cout << "Please enter a grade for assignment " << assignment + 1;
			cout << ", for student " << student + 1 << ": ";
			cin >> gradeBook[student][assignment];
		}
	}
}

void displayGrades(int assignments, int students, double gradeBook[][MAX_ASSIGNMENTS])
{
	cout << endl;
	for(int assignment = 0; assignment < assignments; assignment++)
	{
		for(int student = 0; student < students; student++)
		{
			cout << "The grade for assignment " << assignment + 1;
			cout << ", for student " << student + 1 << " is ";
			cout << gradeBook[student][assignment] << endl;
		}
	}
}

void displayAverage(int assignments, double grades[] )
{
	double total = 0;
	for(int assignment = 0; assignment < assignments; assignment++)
	{
		total = total + grades[assignment];
	}

	cout << "Average for student is " << total/assignments << endl;
}

int main()
{
	double gradeBook[MAX_STUDENTS][MAX_ASSIGNMENTS]; //2D array

	int students;
	int assignments;

	do
	{
		cout << "How many students do you have in your class? ";
		cin >> students;
	}
	while(students > MAX_STUDENTS || students < 0); // input validation loop
	do
	{
		cout << "How many assignments do you have in your class? ";
		cin >> assignments;
	}
	while(assignments > MAX_ASSIGNMENTS || assignments < 0); // input validation loop

	getGrades(assignments, students, gradeBook); // this function fills gradeBook with values
	displayGrades(assignments,students, gradeBook);
	
	int studentIndex;
	cout << "Which student do you want an average for? ";
	cin >> studentIndex;
	studentIndex--;
	displayAverage( assignments, gradeBook[studentIndex]);
	
	return 0;
}