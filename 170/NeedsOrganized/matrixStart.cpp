#include<iostream>

using namespace std;

const int ROWS = 4;
const int COLUMNS = 4;
const int SLICES = 25;

void getMatrixFromUser(int matrix[][COLUMNS]);
void displayMatrix(int matrix[][COLUMNS]);
void displayAllMatrices( int matrices[][ROWS][COLUMNS], int matrixCount);
void getOperation(char& operation);

void main()
{
	int matrices[SLICES][ROWS][COLUMNS] = {0};
	int matrixCount = 0;
	int initialMatrixCount;
	char operation;

	//add data validation (1-SLICES)
	cout << "How many initial matrices? ";
	cin >> initialMatrixCount;

	while(matrixCount < initialMatrixCount)
	{
		cout << "Enter matrix " << matrixCount + 1 << ":\n"; 
		getMatrixFromUser(matrices[matrixCount]);
		matrixCount++;
	}

	getOperation(operation);

	while(operation != 'Q')
	{
		//do the operation
		cout << "This is the operation " << operation << endl;
		switch(operation)
		{
			case '+':

				break;
			case '-':
				break;
			case '*':
				break;
			case 'X':
				break;
			case 'T':
				break;
			case 'D':
				break;
		}

		getOperation(operation);
	}

	//displayAllMatrices( matrices, matrixCount);
}

void getOperation(char& operation)
{
	do
	{
		cout << "Operation? ";
		cin >> operation;
		operation = toupper(operation);
	}
	while(	operation != '+' && 
			operation != '-' &&
			operation != 'Q' &&
			operation != 'T' &&
			operation != 'X' &&
			operation != '*' &&
			operation != 'D'
			);

}

void displayAllMatrices( int matrices[][ROWS][COLUMNS], int matrixCount)
{
	for(int i = 0; i < matrixCount; i ++)
	{
		cout << "Matrix " << i + 1 << endl;
		displayMatrix(matrices[i]);
		cout << endl;
	}
}


void getMatrixFromUser(int matrix[][COLUMNS])
{
	for(int row = 0 ; row < ROWS; row++)
	{
		cout << "  Row " << row + 1 << "? ";
		for(int column = 0 ; column < COLUMNS; column++)
		{
			cin >> matrix[row][column];
		}
	}
}

void displayMatrix(int matrix[][COLUMNS])
{
	for(int row = 0 ; row < ROWS; row++)
	{
		cout << "  Row " << row + 1 << ": ";
		for(int column = 0 ; column < COLUMNS; column++)
		{
			cout << matrix[row][column] << " ";
		}
		cout << endl;
	}
}


