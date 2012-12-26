#include<iostream>
#include<time.h>
using namespace std;

const int BOARD_SIZE = 9;

void initializeBoard( char board[] )
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		board[i] = ' ';
	}
}

void displayBoard( char board[] )
{
	system("cls");
	
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		switch(i)
		{
			case 0: case 1: case 3: case 4: case 6: case 7: 
				cout << board[i] << "|";
				break;
			case 2: case 5:
				cout << board[i] << endl << "-----" << endl;
				break;
			case 8:
				cout << board[i] << endl;
		}
	}
}

bool boardFull( char board[] )
{
	bool result = true;

	for(int i = 0; i < BOARD_SIZE; i++ )
	{
		if(board[i] == ' ')
		{
			result = false;
		}
	}

	return result;
}

void changeTurn( char& turn )
{
	if( turn == 'X' )
	{
		turn = 'O';
	}
	else
	{
		turn = 'X';
	}
}

bool boardHasWinnerAt( char board[], int position1, 
					   int position2, int position3, char& winner)
{
	bool result = false;

	if (board[position1] == board[position2] &&
		board[position2] == board[position3] &&
		board[position1] != ' ' )
	{
		result = true;
		winner = board[position1];
	}

	return result;
}

bool boardHasWinner(char board[], char& winner)
{
	bool result = false;
	
	if( boardHasWinnerAt(board, 0, 1, 2, winner) || 
		boardHasWinnerAt(board, 3, 4, 5, winner) || 
		boardHasWinnerAt(board, 6, 7, 8, winner) || 
		boardHasWinnerAt(board, 0, 3, 6, winner) || 
		boardHasWinnerAt(board, 1, 4, 7, winner) || 
		boardHasWinnerAt(board, 2, 5, 8, winner) || 
		boardHasWinnerAt(board, 0, 4, 8, winner) || 
		boardHasWinnerAt(board, 2, 4, 6, winner))
	{
		result = true;
	}


	return result;
}

void main()
{
	char board[BOARD_SIZE];
	char turn = 'X';
	char winner = 'C';
	int move;

	initializeBoard( board );

	while( !boardHasWinner(board, winner ) && !boardFull(board) )
	{
		displayBoard( board );

		do
		{
			cout << turn << "'s turn(0-8): ";
			cin >> move;
		}
		while(move < 0 || move > 8 || board[move] != ' ' );

		board[move] = turn;

		changeTurn( turn );
	}

	displayBoard( board );

	if( winner == 'C')
	{
		cout << "Cat wins" << endl;
	}
	else
	{
		cout << "The winner is " << winner << endl;
	}
}








