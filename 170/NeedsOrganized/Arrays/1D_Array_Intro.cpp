// this program is an intro to 1D arrays that
// explores array declaration, array initialization, 
// and the accessing of array elements.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_GRADES = 10;

void getGradesToEnter( int& GradesToEnter )
{
	do
	{
		cout << "How many grades do you want to enter? "; 
		cin >> GradesToEnter;
	}
	while(GradesToEnter > MAX_GRADES); 	// This is an input validation loop. If you try to store more values than
}										// the size of your array (the number between the square brackets at 
										// declaration), your program will go "out-of-bounds" during runtime.
										// Basically, this means that your program accessed (or tried to access) 
										// forbidden memory. This must be avoided.

void getGrades( int GradesToEnter, int Grades[] )
{
	for( int i = 0; i < GradesToEnter; i++ )
	{
		cout << "Grade " << i + 1 << "? ";
		cin >> Grades[i];	// array elements are accessed using square brackets, counting from 0
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


int main()
{
	// An array is a list of variables of the same datatype.
	// A 1D arrays is declared with one pair of square brackets after the name of the array.
	// You must put etween the square brackets a constant number indicating the number of array elements.
	//		-An element is an individual value within an array.
	
	int grades[10] = {0}; 			// 10 integers - indexes 0-9 
									//		has a constant between the square brackets
									
	int grades2[MAX_GRADES] = {0}; 	// 10 integers - indexes 0-9
									//		has a constant between the square brackets
	
	//	DO NOT DO THIS:	
	//		int x = 10;
	//		int badArray[x] = {0}; // x is not a constant.

	
	int gradesToEnter = 0;

	getGradesToEnter( gradesToEnter );
	getGrades( gradesToEnter, grades );
	displayGrades( gradesToEnter, grades ); 
	
	copyGrades(grades, grades2, gradesToEnter); // grades2 now equals grades

	return 0;
}








