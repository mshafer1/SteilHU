#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;

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
				cout << ' ';
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

		//get a valid move from the user
		do
		{
			cout << "Enter Move:";
			cin >> move;
		}
		while(move < 0 || move > 8 || 
			(((int)pow(2.0,move) & xMoves) == (int)pow(2.0,move)) ||
			(((int)pow(2.0,move) & oMoves) == (int)pow(2.0,move)));


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
	while(xMoves + oMoves < 511 &&
		((xMoves & 7) != 7) && 
		((xMoves & 56) != 56) && 
		((xMoves & 448) != 448) && 
		((xMoves & 73) != 73) && 
		((xMoves & 146) != 146) && 
		((xMoves & 292) != 292) && 
		((xMoves & 84) != 84) && 
		((xMoves & 273) != 273) && 
		((oMoves & 7) != 7) && 
		((oMoves & 56) != 56) && 
		((oMoves & 448) != 448) && 
		((oMoves & 73 )!= 73) && 
		((oMoves & 146) != 146) && 
		((oMoves & 292) != 292) && 
		((oMoves & 84) != 84) && 
		((oMoves & 273) != 273) 
		);


	//clears the screen before the board is displayed
	system("cls");

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
			cout << ' ';
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






