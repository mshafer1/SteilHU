//this program shows how 3D arrays are made of multiple 2D arrays,
	// how 2D arrays are made of multiple 1D arrays, 
	//and how 1D arrays are made of individual values.
	// This program also shows how elements of a 3D array are passed into functions.

#include<iostream>
#include<time.h>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;

const int COLUMNS = 3;
const int ROWS = 5;
const int SLICES = 4;

void printInt( int x)
{
	cout << "      int " << x << endl;
}

void print1DArray( int x[])
{
	cout << "   1D array:\n"; 
	for(int i = 0; i < COLUMNS; i++)
	{
		printInt(x[i]); // passing in a single value
	}
}

void print2DArray( int x[][COLUMNS]) //this function does not "know" that the 2D Array "x" 
										//is a slice of a 3D array.
{
	cout << " 2D array contains " << ROWS << " 1D arrays:\n\n"; 
	for(int i = 0; i < ROWS; i++)
	{
		print1DArray(x[i]); // passing in a 1D array (a "row" of a "slice")
	}
	cout << endl;
}

void print3DArray( int x[][ROWS][COLUMNS])
{
	cout << "3D array contains " << SLICES << " 2D arrays:\n\n"; 
	for(int s = 0; s < SLICES; s++)
	{
		print2DArray(x[s]); // passing in a "slice" of 3D array A. Note the parameters of 
							//function print2DArray.
	}
}

void initialize( int x[][ROWS][COLUMNS])
{
	cout << "\ninitializing array...\n"; 
	for(int s = 0; s < SLICES; s++)
	{
		for(int i = 0; i < ROWS; i++)
		{
			for(int j = 0; j < COLUMNS; j++)
			{
				x[s][i][j] = rand();
			}
		}
	}
	cout << "array initialized.\n\n";
}

int main()
{
	srand((unsigned int)time(0)); //seed the random number generator
	
	int A[SLICES][ROWS][COLUMNS]; // declaring a 3D array
	initialize(A);
	
	print3DArray(A); 
	//picture the 3D array as a cube, consisting of "slices" of flat 2D arrays.
		// As we have already covered, each 2D array consists of "rows" of 1D arrays, 
		//and each 1D array is made of multiple individual values.
		
	cout << endl << "All values in 3D array have been printed.\n Press enter.\n";
	cin.get();
	
	cout << "slice 0:\n" ;
	print2DArray(A[0]); // A[0] is a 2D array
	
	cout << "slice 0, row 0:\n";
	print1DArray(A[0][0]); // A[0][0] is a 1D array
	
	cout << endl << "slice 0, row 0, position 0:\n";
	printInt(A[0][0][0]); // A[0][0][0] is an integer
	
	return 0;
}
