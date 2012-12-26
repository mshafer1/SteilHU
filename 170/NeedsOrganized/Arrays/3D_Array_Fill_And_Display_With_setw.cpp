//this program creates a 3D array and displays it's contents, using setw to organize the console output.

#include<iostream>
#include<iomanip> // contains setw

using std::cin;
using std::cout;
using std::setw;
using std::endl;

int main()
{
	int A[4][5][6];	
	// 4*5*6 = 120 integers. 120 * 4 bytes = 480 bytes. 
	//Remember, one int is 4 bytes of memory. 3D array A uses 480 bytes of memory.

	for (int slice = 0; slice < 4; slice++)
	{
		for (int row = 0; row < 5; row++)
		{
			for (int column = 0; column < 6; column++)
			{
				A[slice][row][column] = (slice+1) * (row+ 1) * column; 
			}
		}
	}

	cout << endl;
	for (int slice = 0; slice < 4; slice++)
	{
		cout << "slice " << slice << ":\n\n";
		for (int row = 0; row < 5; row++)
		{
			for (int column = 0; column < 6; column++)
			{
				cout << setw(4) << A[slice][row][column]; 
				//setw is what creates the orderly columns the user sees in the console output. 
				//setw(int n) sets the next cout insertion at n character-widths.
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}