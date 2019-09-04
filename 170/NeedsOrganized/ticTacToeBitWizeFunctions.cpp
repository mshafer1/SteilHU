#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;

void DisplayBoard(int xMoves, int oMoves);
bool BoardFull(int xMoves, int oMoves);
void DisplayWinner(int xMoves, int oMoves);
bool HasWon(int Moves);
int NextMove(int xMoves, int oMoves);

//This Tic Tac Toe game uses two integers to represent x's moves and y's moves
//The following pattern is used to store the game board.  The numbers shown are
//used as the exponent of 2 then added to the total for the player whose turn it 
//is.
// 0|1|2
// -----
// 3|4|5
// -----
// 6|7|8


void main()
{
	int xMoves = 0;
	int oMoves = 0;

	//x moves first
	bool xTurn = true;

	int move;

	do
	{
		DisplayBoard(xMoves,oMoves);
		move = NextMove(xMoves,oMoves);

		if(xTurn)
		{
			//pow(x,y) raises x to the y power
			xMoves = xMoves + (int)pow(2.0,move);
			xTurn = false;
		}
		else
		{
			oMoves = oMoves + (int)pow(2.0,move);
			xTurn = true;
		}
	}
	while(!BoardFull(xMoves,oMoves) &&
		!HasWon(xMoves) && 
		!HasWon(oMoves));


	DisplayBoard(xMoves,oMoves);
	DisplayWinner(xMoves,oMoves);
}

void DisplayBoard(int xMoves, int oMoves)
{
	//clears the screen before the board is displayed
		
		system("cls");
		//this for loop is used to display the game board
		for(int i = 0; i < 9; i++)
		{

			if(((int)pow(2.0,i) & xMoves) ==  (int)pow(2.0,i))
			{
				cout << 'X';
			}
			else if (((int)pow(2.0,i) & oMoves) ==  (int)pow(2.0,i))
			{
				cout << 'O';
			}
			else
			{
				cout << i;
			}

			if (i == 2 || i == 5)
			{
				cout << endl;
				cout <<"-----";
				cout << endl;
			}
			else
			{
				cout << "|";
			}
		}
}

int NextMove(int xMoves, int oMoves)
{
	int move;
	
	do
	{
		cout << "Enter Move:";
		cin >> move;
	}
	while(move < 0 || move > 8 || 
		(((int)pow(2.0,move) & xMoves) == (int)pow(2.0,move)) ||
		(((int)pow(2.0,move) & oMoves) == (int)pow(2.0,move)));

	return move;
}

bool HasWon(int Moves)
{
	bool result = false;

	if(((Moves & 7) == 7) || 
	((Moves & 56) == 56) || 
	((Moves & 448) == 448) || 
	((Moves & 73) == 73) || 
	((Moves & 146) == 146) || 
	((Moves & 292) == 292) || 
	((Moves & 84) == 84) || 
	((Moves & 273) == 273))
	{
		result = true;
	}

	return result;
}

void DisplayWinner(int xMoves, int oMoves)
{
	if (HasWon(xMoves))
	{
		cout << "X wins" << endl;
	}
	else if (HasWon(oMoves))
	{
		cout << "O wins" << endl;
	}
	else
	{
		cout << "Cat wins" << endl;
	}
}

bool BoardFull(int xMoves, int oMoves)
{
	return (xMoves + oMoves >= 511);
}