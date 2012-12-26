#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void buildMultiplicationTable(int totalRows, int totalColumns)
{
	int currentColumn = 1;
	int currentRow = 1;

	while ( currentRow <= totalRows )
	{
		currentColumn = 1;

		while ( currentColumn <= totalColumns ) 
		{ //nested while loops (loop inside of another)
			cout << setw (4) << currentColumn * currentRow;
			currentColumn++;
		}

		cout << endl;

		currentRow++;
	}

}


int main()
{
	buildMultiplicationTable(10,10);
	
    cin.get();
    return 0;
}
