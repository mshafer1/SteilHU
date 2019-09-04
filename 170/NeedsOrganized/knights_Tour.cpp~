#include<iostream>
#include<iomanip>

using namespace std;

const long MAX_ROWS = 8;
const long MAX_COLUMNS = 8;

const long HorizonalMoves[] = { 2, 1,-1,-2,-2,-1, 1, 2};
const long VerticalMoves[] =  {-1,-2,-2,-1, 1, 2, 2, 1};

void DisplayBoard(long Board[][MAX_COLUMNS]);
long PossibleMoves(long CurrentRow, long CurrentColumn, long Board[][MAX_COLUMNS], long MoveCount);
void DisplayPossibleMoves(long CurrentRow, long CurrentColumn, long Board[][MAX_COLUMNS], long MoveCount);
bool IsValidKnightsMove(long CurrentRow, long CurrentColumn, long NewRow, long NewColumn, long MoveCount);
void GetMove(long& CurrentRow, long& CurrentColumn, long& MoveCount, long Board[][MAX_COLUMNS]);
bool OnBoard(long Row, long Column);

void main()
{
	long Board[MAX_ROWS][MAX_COLUMNS] = {0};

	long CurrentRow = 0;
	long CurrentColumn = 0;
	
	long MoveCount = 0;

	do
	{
		GetMove(CurrentRow, CurrentColumn, MoveCount, Board);
	}
	while (PossibleMoves(CurrentRow, CurrentColumn, Board, MoveCount) > 0 );

	DisplayBoard(Board);

	if (MoveCount == 64)
	{
		cout << "Congratulations, your knight made it to all 64 squares!" << endl;
	}
	else
	{
		cout << "Sorry, your knight only made it to " << MoveCount << " squares!" << endl;
	}
	
}

void GetMove(long& CurrentRow, 
			 long& CurrentColumn, 
			 long& MoveCount, 
			 long Board[][MAX_COLUMNS])
{
	long NewRow;
	long NewColumn;

	if (PossibleMoves(CurrentRow, CurrentColumn, Board, MoveCount) > 0)
	{
		do
		{
			DisplayBoard(Board);		
			DisplayPossibleMoves(CurrentRow, CurrentColumn, Board, MoveCount);
			
			cout << "Row (1-8)? ";
			cin >> NewRow;
			NewRow--;

			cout << "Column (1-8)? ";
			cin >> NewColumn;
			NewColumn--;
		}
		while(!OnBoard(NewRow,NewColumn) || 
			Board[NewRow][NewColumn] != 0 || 
			!IsValidKnightsMove(CurrentRow, CurrentColumn, NewRow, NewColumn, MoveCount));


		MoveCount++;
		Board[NewRow][NewColumn] = MoveCount;
		CurrentRow = NewRow;
		CurrentColumn = NewColumn;
	}
}

void DisplayBoard(long Board[][MAX_COLUMNS])
{
	system("cls");

	cout << "     1  2  3  4  5  6  7  8" << endl;
	cout << "   ------------------------" << endl;
	
	for (long Row = 0; Row < MAX_ROWS; Row++)
	{
		cout << Row + 1 << "| ";

		for (long Column = 0; Column < MAX_ROWS; Column++)
		{
			cout << setw(3) << Board[Row][Column];
		}

		cout << endl;
	}
}

long PossibleMoves(long CurrentRow, long CurrentColumn, long Board[][MAX_COLUMNS], long MoveCount)
{
	long Result = 0;

	if (MoveCount == 0)
	{
		Result = 64;
	}
	else
	{
		for(int i = 0; i < 8; i++)
		{
			long Row = 	CurrentRow + VerticalMoves[i] ;
			long Column = CurrentColumn + HorizonalMoves[i];

			if (OnBoard(Row,Column) && Board[Row][Column] == 0)
			{
				Result++;
			}
		}
	}

	return Result;
}

void DisplayPossibleMoves(long CurrentRow, long CurrentColumn, long Board[][MAX_COLUMNS], long MoveCount)
{
	cout << "Possible Moves" << endl;

	if(MoveCount > 0)
	{
		for(int i = 0; i < 8; i++)
		{
			long Row = 	CurrentRow + VerticalMoves[i];
			long Column = CurrentColumn + HorizonalMoves[i];

			if (OnBoard(Row,Column) && 	Board[Row][Column] == 0)
			{
				cout << "(" << Row+ 1 <<  "," <<  Column + 1<< ")  ";
			}
		}
	}
	else
	{
		cout << "You can move anywhere on the board.";
	}

	cout << endl;
}

bool IsValidKnightsMove(long CurrentRow, long CurrentColumn, long NewRow, long NewColumn, long MoveCount)
{
	bool Result = false;

	if (MoveCount > 0)
	{
		for(int i = 0; i < 8; i++)
		{
			if(CurrentRow + VerticalMoves[i] == NewRow &&
				CurrentColumn + HorizonalMoves[i] == NewColumn )
			{
				Result = true;
			}
		}
	}
	else
	{
		Result = true;
	}

	return Result;
}

bool OnBoard(long Row, long Column)
{
	bool Result = false;

	if (Row >= 0 && Row < MAX_ROWS && Column >= 0 && Column < MAX_COLUMNS)
	{
		Result = true;
	}

	return Result;
}


