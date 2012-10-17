#include<iostream>

using namespace std;

void main()
{
	int A[4][5][6];	//120 integers * 4 bytes = 480 bytes

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

	for (int slice = 0; slice < 4; slice++)
	{
		for (int row = 0; row < 5; row++)
		{
			for (int column = 0; column < 6; column++)
			{
				cout << setw(4) << A[slice][row][column]; 
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}