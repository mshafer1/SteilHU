//this program performs operations on
//  multiple grades in a class, demonstrating
//  use of the do-while loop.

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
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
		cout << "Enter a grade (-1 to quit)";
		cin >> grade;
		cin.ignore();	

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
	cout << "Average is: " << average << " ";
	
	if (average >= 90)
	{
		cout << "A" << endl;
	}
	else if(average >= 80)
	{
		cout << "B" << endl;
	}
	else if(average >= 70)
	{
		cout << "C" << endl;
	}
	else if(average >= 60)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "F" << endl;
	}

	cout << "Max grade is: " << max_grade <<endl;
	cout << "Min grade is: " << min_grade << endl;

    cin.get();
    return 0;
}

// notice how the do-while loop is clearer than this:

/*	float grade = 0;
    while(grade != -1)
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

		cout << "Enter a grade (-1 to quit)";
		cin >> grade;		
	}
*/
