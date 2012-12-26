#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int row = 1;
	int column = 1;

newRow:
	column = 1;

newColumn:

	cout << setw(4)  << row * column;
	column++;
	
	if( column < 10)
	{
		goto newColumn;
	}

	row++;
	cout << endl;
	if( row < 10 )
	{
		goto newRow;
	}
}
