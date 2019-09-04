#include<iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_ROWS = 4;
const int MAX_COLUMNS = 4;
const int MAX_SLICES = 25;

void GetMatrix1(int Matrix[], int Count)
{
	for (int Column = 0; Column < Count; Column++)
	{
		cin >> Matrix[Column];
	}
}

void GetMatrix(int Matrix[][MAX_COLUMNS])
{
	for (int Row = 0; Row < MAX_ROWS; Row++)
	{
		for (int Column = 0; Column < MAX_COLUMNS; Column++)
		{
			cin >> Matrix[Row][Column];
		}
	}
}

void ShowMatrix(int Matrix[][MAX_COLUMNS])
{
	for (int Row = 0; Row < MAX_ROWS; Row++)
	{
		for (int Column = 0; Column < MAX_COLUMNS; Column++)
		{
			cout << Matrix[Row][Column]  << " ";
		}
		cout << endl;
	}
}

int main()
{
	//int A[10] = {0};
	//GetMatrix1(A, 10);

	int B[MAX_ROWS][MAX_COLUMNS] = {0};

	int Matrices[MAX_SLICES][MAX_ROWS][MAX_COLUMNS] = {0};

	int InitialMatrices;
	int MatricesUsed = 0;

	cin >> InitialMatrices;
	//do data validation must be between 1 and 25

	for (MatricesUsed = 0; MatricesUsed < InitialMatrices; MatricesUsed++ )
	{
		GetMatrix(Matrices[MatricesUsed]);
	}

	ShowMatrix(Matrices[4]);
	
    cin.get();
    return 0;
}
