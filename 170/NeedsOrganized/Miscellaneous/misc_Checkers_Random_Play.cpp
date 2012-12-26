//this program is a checkers game, where both players make random moves.

#include<iostream>
#include<time.h>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

const char WALL = (char)219;
const char MALE = (char)11;
const char FEMALE = (char)12;
const char KING = 'K';
const char QUEEN = 'Q';
const char NONE = ' ';
const int BOARD_SIZE = 8;

void initializeGameBoard( char gameBoard[][BOARD_SIZE] );
void displayGameBoard( char gameBoard[][BOARD_SIZE] );
char gameWinner( char gameBoard[][BOARD_SIZE] );

void makeMove(char gameBoard[][BOARD_SIZE], char player);
void makeRoyalty(char gameBoard[][BOARD_SIZE]);

bool validMove(int fromColumn, int toColumn, 
			   int fromRow, int toRow, 
			   char player, char gameBoard[][BOARD_SIZE]);
bool spotHasPlayersPiece(char gameBoard[][BOARD_SIZE], char player, int row, int column );
bool spotAvailable(char gameBoard[][BOARD_SIZE], int row, int column );
bool moveDirectionIsValid( int fromRow, int toRow, char player );
bool moveDistanceIsValid(int fromColumn, int toColumn, 
						int fromRow, int toRow, 
						char player, char gameBoard[][BOARD_SIZE] );
void getRandomMove(int& fromRow, int& toRow, char& fromColumn, char& toColumn );


int main()
{
	char gameBoard[BOARD_SIZE][BOARD_SIZE];
	char player = FEMALE;

	srand( time( 0 ) );
	initializeGameBoard( gameBoard );

	while( gameWinner( gameBoard ) == NONE )
	{
		displayGameBoard( gameBoard );
		makeMove( gameBoard, player );
		
		if( player == FEMALE)
		{
			player = MALE;
		}
		else
		{
			player = FEMALE;
		}
		cin.get();
	}

	displayGameBoard( gameBoard );
	if( gameWinner( gameBoard ) == FEMALE )
	{
		cout << "Female wins " << endl;
	}
	if( gameWinner( gameBoard ) == MALE )
	{
		cout << "Male wins " << endl;
	}
	return 0;
}

void initializeGameBoard( char gameBoard[][BOARD_SIZE] )
{
	for( int row = 0; row < BOARD_SIZE; row++ )
	{
		for( int column = 0; column < BOARD_SIZE; column++ )
		{
			if( (row + column) % 2 == 0 )
			{
				gameBoard[row][column] = WALL;
			}
			else if( row < 3)
			{
				gameBoard[row][column] = MALE;
			}
			else if( row > BOARD_SIZE - 4)
			{
				gameBoard[row][column] = FEMALE;
			}   
			else
			{
				gameBoard[row][column] = ' ';
			}
		}
	}
}

void displayGameBoard( char gameBoard[][BOARD_SIZE] )
{
	cout << " ABCDEFGH" << endl;
	for( int row = 0; row < BOARD_SIZE; row++ )
	{
		cout << row + 1;
		for( int column = 0; column < BOARD_SIZE; column++ )
		{
			cout << gameBoard[row][column];
		}
		cout << endl;
	}
} 

bool spotHasPlayersPiece(char gameBoard[][BOARD_SIZE], char player, int row, int column )
{
	bool result = false;
	if( player == FEMALE  && ( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN ))
	{
		result = true;
	}
	if( player == MALE  && ( gameBoard[row][column] == MALE || gameBoard[row][column] == KING ))
	{
		result = true;
	}

	return result;
}

bool spotAvailable(char gameBoard[][BOARD_SIZE], int row, int column )
{
	return ( gameBoard[row][column] == ' ' );
}

bool moveDirectionIsValid( int fromRow, int toRow, char player )
{
	bool result = false;

	if( player == KING || player == QUEEN )
	{
		result = true;
	}
	if(player == FEMALE && fromRow > toRow )
	{
		result = true;
	}
	else if(player == MALE && fromRow < toRow )
	{
		result = true;
	}

	return result;
}

bool moveDistanceIsValid(int fromColumn, int toColumn, 
						int fromRow, int toRow, 
						char player, char gameBoard[][BOARD_SIZE] )
{
	bool result = false;

	int columnDistance = abs(fromColumn - toColumn);
	int rowDistance = abs(fromRow - toRow);

	int rowJumped = (fromRow + toRow) /2;
	int columnJumped = (fromColumn + toColumn) /2;

	if( (columnDistance == 1 && rowDistance == 1 ) )
	{
		result = true;
	}
	else if( columnDistance == 2 && rowDistance == 2  && 
		gameBoard[rowJumped][columnJumped] != player &&
		gameBoard[rowJumped][columnJumped] != ' ')
	{
		gameBoard[rowJumped][columnJumped] = ' ';
		result = true;
	}
	return result;
}

bool validMove(int fromColumn, int toColumn, 
			   int fromRow, int toRow, 
			   char player, char gameBoard[][BOARD_SIZE])
{
	bool result = false;

	if(spotHasPlayersPiece(gameBoard, player, fromRow, fromColumn) && 
		spotAvailable(gameBoard, toRow, toColumn) && 
		moveDirectionIsValid(fromRow, toRow, gameBoard[fromRow][fromColumn] ) &&
		moveDistanceIsValid(fromColumn, toColumn, fromRow, toRow, player, gameBoard))
	{
		result = true;
	}
	return result;
}

void makeRoyalty(char gameBoard[][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		if(gameBoard[0][i] == FEMALE)
		{
			gameBoard[0][i] = QUEEN;
		}
		if(gameBoard[BOARD_SIZE - 1][i] == MALE)
		{
			gameBoard[BOARD_SIZE - 1][i] = KING;
		}
	}
}

void getRandomMove(int& fromRow, int& toRow, char& fromColumn, char& toColumn )
{
	fromRow = (rand() % BOARD_SIZE)  + 1;
	toRow = (rand() % BOARD_SIZE)  + 1;

	fromColumn = (char)(rand() % BOARD_SIZE ) + 'A';
	toColumn = (char)(rand()% BOARD_SIZE ) + 'A';
}

void makeMove(char gameBoard[][BOARD_SIZE], char player)
{
	int fromRow;
	int toRow;
	char fromColumn;
	char toColumn;

	cout << player << "'s Turn: " << endl;
	do
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
	while( !validMove(fromColumn - 'A', toColumn - 'A', fromRow - 1, toRow -1, player, gameBoard));

	gameBoard[toRow - 1][toColumn - 'A'] = gameBoard[fromRow - 1][fromColumn - 'A'];
	gameBoard[fromRow - 1][fromColumn - 'A'] = ' ';

	makeRoyalty(gameBoard);
}

char gameWinner( char gameBoard[][BOARD_SIZE] )
{
	char result = NONE;
	int males = 0;
	int females = 0;

	for( int row = 0; row < BOARD_SIZE; row++ )
	{
		for( int column = 0; column < BOARD_SIZE; column++ )
		{
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{
				females++;
			}
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{
				males++;
			}
		}
	}

	if(males == 0)
	{
		result = FEMALE;
	}
	else if( females == 0)
	{
		result = MALE;
	}

	return result;
}



