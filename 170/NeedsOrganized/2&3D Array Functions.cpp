#include<iostream>
#include<time.h>
using namespace std;

const int COLUMNS = 10;
const int ROWS = 5;
const int SLICES = 4;

void printInt( int x)
{
	cout << "int " << x << endl;
}

void print1DArray( int x[])
{
	cout << "1D array\n"; 
	for(int i = 0; i < COLUMNS; i++)
	{
		printInt(x[i]);
	}
	cout << endl;
}

void print2DArray( int x[][COLUMNS])
{
	cout << "2D array\n"; 
	for(int i = 0; i < ROWS; i++)
	{
		print1DArray(x[i]);
	}
	cout << endl;
}

void print3DArray( int x[][ROWS][COLUMNS])
{
	cout << "3D array\n"; 
	for(int s = 0; s < SLICES; s++)
	{
		print2DArray(x[s]);
	}
	cout << endl;
}

void initialize( int x[][ROWS][COLUMNS])
{
	cout << "initializing array\n "; 
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
}

void main()
{
	srand((unsigned int)time(0));
	int A[SLICES][ROWS][COLUMNS];
	initialize(A);
	print3DArray(A);
	print2DArray(A[0]);
	print1DArray(A[0][0]);
	printInt(A[0][0][0]);
}
