//this code lays the foundation for a program that performs
//operations on 2D Arrays, or matrices

#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;

const int MAX_MATRICES = 25;
const int MATRIX_SIZE = 4;

void getUserCommand( char& userCommand )
{
	cout << "Operation? ";
	cin >> userCommand;
}

void getInitialMatrices( int matrices[][MATRIX_SIZE][MATRIX_SIZE], int& matricesAvailable, int matricesToStartWith)
{
	do
	{
		cout << "Enter matrix " << matricesAvailable + 1 << ":\n";
		for(int row = 0; row < MATRIX_SIZE; row++)
		{
			cout << "  Row " << row + 1 << "? ";
			for(int column = 0; column < MATRIX_SIZE; column++)
			{
				cin >> matrices[matricesAvailable][row][column];
			}
		}
		matricesAvailable++;
	}
	while(matricesAvailable < matricesToStartWith);
}

void display (int matrix[][MATRIX_SIZE] )
{
	for(int row = 0; row < MATRIX_SIZE; row++)
	{
		cout << "  Row " << row + 1 << ": ";
		for(int column = 0; column < MATRIX_SIZE; column++)
		{
			cout << matrix[row][column] << " ";
		}
		cout << endl;
	}
}


int indexFromUser( char prompt[], int matricesAvailable )
{
	int result = 0;
	do
	{
		cout << prompt;
		cin >> result;
	}
	while(result < 1 || result > matricesAvailable);
	result--;

	return result;
}

int main()
{
	int matrices[MAX_MATRICES][MATRIX_SIZE][MATRIX_SIZE];
	int matricesToStartWith;
	int matricesAvailable = 0;
	
	char userCommand;

	do
	{
		cout << "How many initial matrices? ";
		cin >> matricesToStartWith;
	}
	while(matricesToStartWith < 1 || matricesToStartWith > MAX_MATRICES);

	getInitialMatrices( matrices, matricesAvailable, matricesToStartWith);

	do
	{
		getUserCommand( userCommand );

		int firstMatrix = 0;
		int secondMatrix = 0;

		switch( toupper( userCommand)  )
		{
			case 'D':				
				firstMatrix = indexFromUser( "Matrix to display? ", matricesAvailable  );
				display( matrices[firstMatrix] );
				break;
			case '+':
				firstMatrix  = indexFromUser( "First Matrix For +? ", matricesAvailable  );
				secondMatrix  = indexFromUser( "Second Matrix For +? ", matricesAvailable  );
				//add();
				break;
			case '-':
				firstMatrix  = indexFromUser( "First Matrix For -? ", matricesAvailable  );
				secondMatrix  = indexFromUser( "Second Matrix For -? ", matricesAvailable  );
				//display();
				break;
			case '*':
				//display();
				break;
			case 'T':
				//display();
				break;
			case 'X':
				//display();
				break;
			case 'Q':
				//do nothing
				break;
			default:
				cout << "Invalid command...\n";
		}
	}
	while( toupper(userCommand) != 'Q');
    
    cin.get();
    return 0;
}
