#include <iostream.h>
#include <iomanip.h>


void BuildMultiplicationTable(int TotalRows, int TotalColumns)
{
	int CurrentColumn = 1;
	int CurrentRow = 1;

	while ( CurrentRow <= TotalRows )
	{
		CurrentColumn = 1;

		while ( CurrentColumn <= TotalColumns )
		{
			cout << setw (4) << CurrentColumn * CurrentRow;
			CurrentColumn++;
		}

		cout << endl;

		CurrentRow++;
	}

}


void main()
{
	BuildMultiplicationTable(10,10);
}