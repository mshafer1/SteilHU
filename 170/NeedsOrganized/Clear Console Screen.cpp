#include<iostream>
#include<stdlib.h>
using namespace std;

void main()
{
	float total;
	float average;
	int num_of_grades;
	float grade;
	float max_grade = 0;
	float min_grade = 100;
	

	grade = 0;
	total = 0;
	num_of_grades = 0;

	do
	{
		system("cls");
		cout << "Enter a grade (-1 to quit)";
		cin >> grade;		

		if ( grade >= 0)
		{
			total = total + grade;
			num_of_grades = num_of_grades + 1;

			if(grade > max_grade)
			{
				max_grade = grade;
			}
			
			if(grade < min_grade)
			{
				min_grade = grade;
			}
		}
	}while(grade >= 0);
	
	average = total / num_of_grades;
	cout << "Average is: " << average << endl;
	
	if (average >= 90)
	{
		cout << "A";
	}
	else if(average >= 80)
	{
		cout << "B";
	}
	else if(average >= 70)
	{
		cout << "C";
	}
	else if(average >= 60)
	{
		cout << "D";
	}
	else
	{
		cout << "F";
	}

	cout << "Max grade is: " << max_grade <<endl;
	cout << "Min grade is: " << min_grade << endl;

}
