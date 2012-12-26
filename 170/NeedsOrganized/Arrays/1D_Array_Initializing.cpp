//this program initializes a 1D array of grades by
// 	using a loop that prompts the user for data,
//	then the data is displayed.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//There are two typical ways to initialize arrays; at the declaration and 
//using a counted loop.  If arrays are not initialized in C++ their values 
// they are filled with garbage.

//When an array is initialized at the declaration, a value for each element 
//is placed inside of {} separated by commas.  The values are placed 
//into the array in the same order as they appear in the comma 
//separated list.  If the comma separated list contains too many 
//values, any attempt to compile will fail.  If the comma separated 
//list contains too few values, the remaining elements will contain 0’s.
//
//The second method used to initialize an array is using a counted loop. 
//An index variable is initialized to 0 and the loop continues until the
//index is at the array size -1.  Within the loop the array at each index
//should be set to its desired initial value.


int main()
{
	const int MAX_GRADES = 10;

	float Grades[MAX_GRADES] = {0}; // or {67, 98, 89, 56, 98, 78, 89};
	int CurrentGrade;

	cout << endl;
	
	for (CurrentGrade = 0; CurrentGrade < MAX_GRADES; CurrentGrade++)
	{
		cout << "Please enter a grade for test " << CurrentGrade + 1 << ": ";
		cin >> Grades[CurrentGrade];
	}

	for (CurrentGrade = 0; CurrentGrade < MAX_GRADES; CurrentGrade++ )
	{
		cout << "Grade for test " << CurrentGrade + 1 << " is " << Grades[CurrentGrade] << endl;
	}
	return 0;
}
