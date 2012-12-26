#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

const int BOARD_SIZE = 9;

void showFlashingText(char text[])
{
		time_t t;
	for(int i = 0; i < 3; i++)
	{
		system("cls");
		t = time(NULL);
		while(time(NULL) == t)
		{
			cout << "\a";
		}
		cout << text;
		t = time(NULL);
		while(time(NULL) == t);

	}
}

bool winnerFound( const char board[], char player)
{
	bool result = false;

	if( ( board[0] == player && board[1] == player && board[2] == player ) || 
		( board[3] == player && board[4] == player && board[5] == player ) || 
		( board[6] == player && board[7] == player && board[8] == player ) || 
		( board[0] == player && board[3] == player && board[6] == player ) || 
		( board[1] == player && board[4] == player && board[7] == player ) || 
		( board[2] == player && board[5] == player && board[8] == player ) || 
		( board[0] == player && board[4] == player && board[8] == player ) || 
		( board[2] == player && board[4] == player && board[6] == player )) 
	{
		result = true;
	}

	return result;
}

void displayBoard( const char board[] )
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		cout << board[i];

		if(i == 2 || i == 5 )
		{
			cout << endl << "-----"  << endl;
		}
		else if( i != 8 )
		{
			cout << "|";
		}
	}
}

void displayWhosTurnItIs ( bool xTurn )
{
	if(xTurn)
	{
		cout << "\nX's turn\n";
	}
	else
	{
		cout << "\nO's turn\n";
	}
}

void makeMove(int& move, bool& xTurn, char board[])
{
	do
	{
		cout << "Enter move(1-9): " ;
		cin >> move;
		move--;
	}
	while(	move < 0 ||
			move > 8 || 
			board[move] == 'X' || 
			board[move] == 'O');

	if(xTurn)
	{
		board[move] = 'X';
		xTurn = false;
	}
	else
	{
		board[move] = 'O';
		xTurn = true;
	}
}

void displayWinner( bool& continueGame, int movesMade, const char board[] )
{
	if( winnerFound(board,'X'))
	{
		showFlashingText("x wins\n");
		continueGame = false;
	}
	else if( winnerFound(board,'O'))
	{
		showFlashingText("o wins\n");
		continueGame = false;
	}
	else if( movesMade == 9) 
	{
		cout << "Cat wins\n";
		continueGame = false;
	}
}

void main()
{
	char board[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};

	bool xTurn = true;
	int move;
	int movesMade = 0;
	bool continueGame = true; 

	while(continueGame)
	{
		system("cls");

		displayWinner( continueGame, movesMade, board );
		displayBoard( board );

		if( continueGame )
		{
			movesMade++;
			displayWhosTurnItIs ( xTurn );
			makeMove( move, xTurn, board);
		}

	}
}