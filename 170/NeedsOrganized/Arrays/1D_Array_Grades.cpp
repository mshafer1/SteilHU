//this program receives grades from the user, stores them in a 1D array, and then displays them.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_GRADES = 100; 	//global constants
									// MAX_GRADES is much clearer than '100.' Global constants improve readability.
									// Global constants can be quickly and reliably changed to represent other values in our source code.
							

void displayGrades(const int grades[], int gradeCount);
void getGrades(int grades[], int& gradeCount);

int main()
{
	int gradeCount;
	int grades[MAX_GRADES];	//here we allocate enough memory to store 100 integers

	getGrades(grades, gradeCount);	
	displayGrades(grades, gradeCount);
	return 0;

}

void displayGrades(const int grades[], int gradeCount)
{
	cout << endl;
	for(int i = 0; i < gradeCount; i++)
	{
		cout << grades[i] << endl;
	}
}

void getGrades(int grades[], int& gradeCount)	// Notice how grades does not use the reference
{												// operator ('&'), yet its value is persistent 
	do											//regardless of scope. This is because grades is a pointer.
	{
		cout << "How many grades will you enter? ";
		cin >> gradeCount;
	}
	while(gradeCount < 0 || gradeCount > MAX_GRADES); 	// input validation loop. 

	for(int i = 0; i < gradeCount; i++)
	{
		cin >> grades[i];
	}
}
