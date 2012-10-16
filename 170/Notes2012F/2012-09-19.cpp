#include <iostream>
#include <time.h>
 
using namespace std;

const int BOARD_SIZE = 3;

void initializeBoard(char board[][BOARD_SIZE]);
void displayBoard(char board[][BOARD_SIZE]);
bool isGameOver(char board[][BOARD_SIZE]);
bool didPlayerWin(char board[][BOARD_SIZE], char player);
void getUsersMove(char board[][BOARD_SIZE], char turn);

//goal - working tic-tac-toe game
//state who wins, X, O, or cat
//use function as much as possible
//finish the isGameOver function
void main()
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initializeBoard(board);
	displayBoard(board);

	char turn = 'X';

	while(!isGameOver(board))
	{
		displayBoard(board);
		getUsersMove(board, turn);
		turn = (turn == 'X')?'O':'X';
	}

	system("pause");

	//operators unary, binary, ternary
}

void initializeBoard(char board[][BOARD_SIZE])
{
	char c = '1';
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = c;
			c++;
		}
	}
}

void displayBoard(char board[][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j];
			if(j < BOARD_SIZE -1)
			{
				cout << "|";
			}
		}
		if(i < BOARD_SIZE -1 )
		{
			cout << endl << "-----" << endl;
		}

	}
}

bool isGameOver(char board[][BOARD_SIZE])
{
	bool result = false;
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
		}
	}
	return result;
}
void getUsersMove(char board[][BOARD_SIZE], char turn)
{
	int move;
	int row;
	int col;
	do
	{
		cout << turn << "'s turn > ";
		cin >> move;

		row = (move-1)/BOARD_SIZE;
		col = (move-1)%BOARD_SIZE;
	}
	while( move < 1 || move > 9 ||
		 board[row][col] == 'X' || board[row][col] == 'O');
	
	board[row][col] = turn;

}


