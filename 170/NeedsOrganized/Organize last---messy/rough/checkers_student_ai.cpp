// Not sure what to do with this.

#include<iostream>
#include<time.h>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

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

void makeMove(char gameBoard[][BOARD_SIZE], char player, int malePlayer, int femalePlayer);
void makeRoyalty(char gameBoard[][BOARD_SIZE]);

bool validMove(int fromColumn, int toColumn, 
			   int fromRow, int toRow, 
			   char player, char gameBoard[][BOARD_SIZE]);
bool spotHasPlayersPiece(char gameBoard[][BOARD_SIZE], char player, int row, int column );
bool moveDirectionIsValid( int fromRow, int toRow, char player );
bool moveDistanceIsValid(int fromColumn, int toColumn, 
						int fromRow, int toRow, 
						char player, char gameBoard[][BOARD_SIZE] );
void getRandomMove(int& fromRow, int& toRow, int& fromColumn, int& toColumn );

bool femaleMovePossible( char gameBoard[][BOARD_SIZE] );
bool maleMovePossible( char gameBoard[][BOARD_SIZE] );

void male1Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void male2Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void male3Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn, int& Moves );
void male4Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void male5Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void male6Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void male7Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void male8Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void maleRandomMove( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );

void female1Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female2Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female3Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female4Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female5Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female6Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female7Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void female8Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
void femaleRandomMove( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );

int main()
{
	char gameBoard[BOARD_SIZE][BOARD_SIZE];
	char player = FEMALE;

	srand( time( 0 ) );

	//play one game between each male and female AI
	for(int male = 1; male <= 9; male++)
	{
		for(int female = 1; female <= 9; female++)
		{
			initializeGameBoard( gameBoard );

			//play until there is a winner or the players whose turn it is can not move
			while( gameWinner( gameBoard ) == NONE && (
				   ( maleMovePossible( gameBoard ) && player == MALE ) || 
				   ( femaleMovePossible( gameBoard) && player == FEMALE ) ) )
			{
				makeMove( gameBoard, player, male, female );
				
				//change whose turn it is
				if( player == FEMALE)
				{
					player = MALE;
				}
				else
				{
					player = FEMALE;
				}
			}

			//displayGameBoard( gameBoard );
			
			char winner =  gameWinner( gameBoard );
			
			//a player wins if there are no more of the opponents peaces or their opponents can not move
			if( winner == FEMALE || ( winner == NONE && !maleMovePossible( gameBoard ) ) )
			{
				cout << "Female " << female << " beat male " << male  << endl;
			}
			else if( winner == MALE || ( winner == NONE && !femaleMovePossible( gameBoard ) ) )
			{
				cout << "Male " << male << " beat female " << female  << endl;
			}
		}
		cout << endl; 
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
				gameBoard[row][column] = NONE;
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
		gameBoard[rowJumped][columnJumped] != NONE )
	{
		result = true;
	}
	return result;
}

bool validMove(int fromColumn, int toColumn, 
			   int fromRow, int toRow, 
			   char player, char gameBoard[][BOARD_SIZE])
{
	bool result = false;

	if( spotHasPlayersPiece(gameBoard, player, fromRow, fromColumn) && 
		gameBoard[toRow][toColumn] == NONE && 
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

void getRandomMove(int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	fromRow = rand() % BOARD_SIZE;
	toRow = rand() % BOARD_SIZE;

	fromColumn = rand() % BOARD_SIZE;
	toColumn = rand()% BOARD_SIZE;
}

void makeMove(char gameBoard[][BOARD_SIZE], char player, int malePlayer, int femalePlayer)
{
	int fromRow;
	int fromColumn;
	int toRow;
	int toColumn;

	int c=1;
	do
	{
		if( player == MALE )
		{
			switch(malePlayer)
			{
				case 1:	male1Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 2:	male2Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 3:	male3Move(gameBoard, fromRow, toRow, fromColumn, toColumn,c); break;
				case 4:	male4Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 5:	male5Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 6:	male6Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 7:	male7Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 8:	male8Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 9:	maleRandomMove(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
			}
		c++;
		}
		
		else
		{
			switch(femalePlayer )
			{
				case 1:	female1Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 2:	female2Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 3:	female3Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 4:	female4Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 5:	female5Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 6:	female6Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 7:	female7Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 8:	female8Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 9:	femaleRandomMove(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
			}
		}
	}
	while( !validMove(fromColumn, toColumn, fromRow, toRow, player, gameBoard));

	//make the move
	gameBoard[toRow][toColumn] = gameBoard[fromRow][fromColumn];
	gameBoard[fromRow][fromColumn] = NONE;

	//move is a jump so remove the piece jumped
	if( abs( toRow - fromRow ) > 1 )
	{
		gameBoard[( toRow + fromRow ) / 2][( toColumn + fromColumn) / 2] = NONE;
	}

	makeRoyalty(gameBoard);
}

bool maleMovePossible( char gameBoard[][BOARD_SIZE] )
{
	bool moveFound = false;

	for( int row = 0; row < BOARD_SIZE && !moveFound; row++ )
	{
		for( int column = 0; column < BOARD_SIZE && !moveFound; column++ )
		{
			if(gameBoard[row][column] == MALE || gameBoard[row][column] == KING)
			{
				//can jump down and left
				if( column > 1 && 
					(gameBoard[row + 1][column - 1] == FEMALE || gameBoard[row + 1][column - 1] == QUEEN) &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				//can jump down and right
				if( column < 6 && 
					(gameBoard[row + 1][column + 1] == FEMALE || gameBoard[row + 1][column + 1] == QUEEN)&&
					gameBoard[row + 2][column + 2] == NONE )
				{
					moveFound = true;
				}
				//can move down and left
				if( column > 0 && gameBoard[row + 1][column - 1] == NONE )
				{
					moveFound = true;
				}
				//can move down and right
				if( column < 7 && gameBoard[row + 1][column + 1] == NONE )
				{
					moveFound = true;
				}
			}
			if( gameBoard[row][column] == KING )
			{
				//can jump up and left
				if( column > 1 && 
					(gameBoard[row - 1][column - 1] == FEMALE || gameBoard[row - 1][column - 1] == QUEEN)&&
					gameBoard[row - 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				//can jump up and right
				if( column < 6 && 
					(gameBoard[row - 1][column + 1] == FEMALE || gameBoard[row - 1][column + 1] == QUEEN)&&
					gameBoard[row - 2][column + 2] == NONE )
				{
					moveFound = true;
				}
				//can move up and left
				if( column > 0 && gameBoard[row - 1][column - 1] == NONE )
				{
					moveFound = true;
				}
				//can move up and right
				if( column < 7 && gameBoard[row - 1][column + 1] == NONE )
				{
					moveFound = true;
				}
			}
		}
	}
	return moveFound;
}

bool femaleMovePossible( char gameBoard[][BOARD_SIZE] )
{
	bool moveFound = false;

	for( int row = 0; row < BOARD_SIZE && !moveFound; row++ )
	{
		for( int column = 0; column < BOARD_SIZE && !moveFound; column++ )
		{
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{
				if( column > 1 && 
					(gameBoard[row - 1][column - 1] == MALE || gameBoard[row - 1][column - 1] == KING )&&
					gameBoard[row - 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				if( column < 6 && 
					(gameBoard[row - 1][column + 1] == MALE || gameBoard[row - 1][column + 1] == KING )&&
					gameBoard[row - 2][column + 2] == NONE )
				{
					moveFound = true;
				}
				if( column > 0 && gameBoard[row - 1][column - 1] == NONE )
				{
					moveFound = true;
				}
				if( column < 7 && gameBoard[row - 1][column + 1] == NONE )
				{
					moveFound = true;
				}
			}
			if( gameBoard[row][column] == QUEEN )
			{
				if( column > 1 && 
					(gameBoard[row + 1][column - 1] == MALE || gameBoard[row + 1][column - 1] == KING)&&
					gameBoard[row + 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				if( column < 6 && 
					(gameBoard[row + 1][column + 1] == MALE ||gameBoard[row + 1][column + 1] == KING )&&
					gameBoard[row + 2][column + 2] == NONE )
				{
					moveFound = true;
				}
				if( column > 0 && gameBoard[row + 1][column - 1] == NONE )
				{
					moveFound = true;
				}
				if( column < 7 && gameBoard[row + 1][column + 1] == NONE )
				{
					moveFound = true;
				}
			}
		}
	}
	return moveFound;
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

void male1Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	bool safeMove = true;
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == KING )
			{
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) && 
					gameBoard[row - 2][column - 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) && 
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) && 
					gameBoard[row + 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) && 
					gameBoard[row + 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
		}	
	}

	for(int row = BOARD_SIZE - 1; row >= 0 && !jumpFound; row--)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{		
				//safe to move down and right
				if( ((gameBoard[row + 2][column] == QUEEN || gameBoard[row + 2][column] == FEMALE) && gameBoard[row][column + 2] == NONE) || ((gameBoard[row][column + 2] == QUEEN) && gameBoard[row + 2][column] == NONE) )
				{
					safeMove = false;
				}
				else
				{
					safeMove = true;
				}

				if( column < 7 && 
					gameBoard[row + 1][column + 1] == NONE &&
					gameBoard[row + 2][column + 2] != QUEEN &&
					gameBoard[row + 2][column + 2] != FEMALE &&
					safeMove )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column + 1;
				}
				//safe to move down and left
				if( ((gameBoard[row + 2][column] == QUEEN || gameBoard[row + 2][column] == FEMALE) && gameBoard[row][column - 2] == NONE) || ((gameBoard[row][column - 2] == QUEEN) && gameBoard[row + 2][column] == NONE) )
				{
					safeMove = false;
				}
				else
				{
					safeMove = true;
				}

				if( column > 0 && 
					gameBoard[row + 1][column - 1] == NONE &&
					gameBoard[row + 2][column - 2] != QUEEN &&
					gameBoard[row + 2][column - 2] != FEMALE &&
					safeMove )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column - 1;
				}
			}

			if( gameBoard[row][column] == KING )
			{
				//safe to move up and left
				if( (gameBoard[row - 2][column] == QUEEN && gameBoard[row][column - 2] == NONE) || ((gameBoard[row][column - 2] == FEMALE || gameBoard[row][column - 2] == QUEEN) && gameBoard[row - 2][column] == NONE) )
				{
					safeMove = false;
				}
				else
				{
					safeMove = true;
				}

				if( column > 0 &&  
					gameBoard[row - 1][column - 1] == NONE &&
					gameBoard[row - 2][column - 2] != QUEEN &&
					safeMove )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 1;
					toColumn = column - 1;
				}
				//safe move up and right
				if( (gameBoard[row - 2][column] == QUEEN && gameBoard[row][column + 2] == NONE) || ((gameBoard[row][column + 2] == FEMALE || gameBoard[row][column + 2] == QUEEN) && gameBoard[row - 2][column] == NONE) )
				{
					safeMove = false;
				}
				else
				{
					safeMove = true;
				}

				if( column < 7 && 
					gameBoard[row - 1][column + 1] == NONE &&
					gameBoard[row - 2][column + 2] != QUEEN &&
					safeMove )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 1;
					toColumn = column + 1;
				}
			}
		}	
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}

void male2Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool moveFound = false;

// if regular player
	for(int row = 0; row < BOARD_SIZE - 2; row++)
	{
		for(int column = 0; column < BOARD_SIZE; column++)
		{
			if(gameBoard[row][column] == MALE)
			{
				
				if( column > 1 && 
					(gameBoard[row + 1][column - 1] == FEMALE || gameBoard[row + 1][column - 1] == QUEEN) &&
					gameBoard[row + 2][column - 2] == NONE &&
					gameBoard[row + 3][column - 1] != FEMALE &&
					gameBoard[row + 3][column - 1] != QUEEN &&
					gameBoard[row + 3][column - 3] != FEMALE &&
					gameBoard[row + 3][column - 3] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column - 2;
				}
				else if( column < 6 && 
					(gameBoard[row + 1][column + 1] == FEMALE || gameBoard[row + 1][column + 1] == QUEEN)&&
					gameBoard[row + 2][column + 2] == NONE &&
					gameBoard[row + 3][column + 1] != FEMALE &&
					gameBoard[row + 3][column + 1] != QUEEN &&
					gameBoard[row + 3][column + 3] != FEMALE &&
					gameBoard[row + 3][column + 3] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column + 2;
				} 
				else if( column > 1 && 
					(gameBoard[row + 1][column - 1] == FEMALE || gameBoard[row + 1][column - 1] == QUEEN) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column - 2;
				}
				
				
				else if( column < 6 && 
					(gameBoard[row + 1][column + 1] == FEMALE || gameBoard[row + 1][column + 1] == QUEEN) &&
					gameBoard[row + 2][column + 2] == NONE)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
		}
	}
//if King
	for(int row = 0; row < BOARD_SIZE - 2 && row > 2; row++)
	{
		for(int column = 0; column < BOARD_SIZE; column++)
		{
			if(gameBoard[row][column] == KING)
			{
				if( column > 1 && 
					(gameBoard[row + 1][column - 1] == FEMALE || gameBoard[row + 1][column - 1] == QUEEN) &&
					gameBoard[row + 2][column - 2] == NONE &&
					gameBoard[row + 3][column - 1] != FEMALE &&
					gameBoard[row + 3][column - 1] != QUEEN &&
					gameBoard[row + 3][column - 3] != FEMALE &&
					gameBoard[row + 3][column - 3] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column - 2;
				}
				else if( column < 6 && 
					(gameBoard[row + 1][column + 1] == FEMALE || gameBoard[row + 1][column + 1] == QUEEN)&&
					gameBoard[row + 2][column + 2] == NONE &&
					gameBoard[row + 3][column + 1] != FEMALE &&
					gameBoard[row + 3][column + 1] != QUEEN &&
					gameBoard[row + 3][column + 3] != FEMALE &&
					gameBoard[row + 3][column + 3] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column + 2;
				}
				else if( column > 1 && 
					(gameBoard[row - 1][column - 1] == FEMALE || gameBoard[row - 1][column - 1] == QUEEN) &&
					gameBoard[row - 2][column - 2] == NONE &&
					gameBoard[row - 3][column - 1] != FEMALE &&
					gameBoard[row - 3][column - 1] != QUEEN &&
					gameBoard[row - 3][column - 3] != FEMALE &&
					gameBoard[row - 3][column - 3] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row - 2;
					toColumn = column - 2;
				}
				else if( column < 6 && 
					(gameBoard[row - 1][column + 1] == FEMALE || gameBoard[row - 1][column + 1] == QUEEN) &&
					gameBoard[row - 2][column + 2] == NONE &&
					gameBoard[row - 3][column + 1] != FEMALE &&
					gameBoard[row - 3][column + 1] != QUEEN &&
					gameBoard[row - 3][column + 3] != FEMALE &&
					gameBoard[row - 3][column + 3] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row - 2;
					toColumn = column + 2;
				} 
				else if( column > 1 && 
					(gameBoard[row + 1][column - 1] == FEMALE || gameBoard[row + 1][column - 1] == QUEEN) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column - 2;
				}				
				else if( column < 6 && 
					(gameBoard[row + 1][column + 1] == FEMALE || gameBoard[row + 1][column + 1] == QUEEN) &&
					gameBoard[row + 2][column + 2] == NONE)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row + 2;
					toColumn = column + 2;
				}
				else if( column > 1 && 
					(gameBoard[row - 1][column - 1] == FEMALE || gameBoard[row - 1][column - 1] == QUEEN) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row - 2;
					toColumn = column - 2;
				}
				else if( column < 6 && 
					(gameBoard[row - 1][column + 1] == FEMALE || gameBoard[row - 1][column + 1] == QUEEN) &&
					gameBoard[row - 2][column + 2] == NONE)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column;
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
		}
	}
	if(!moveFound)
	{
		for(int row = 0; row < BOARD_SIZE - 1; row++)
		{
			for(int column = 0; column < BOARD_SIZE - 1; column++)
			{
				if((column == 1 || column == 7) &&
					(gameBoard[row][column] == MALE || gameBoard[row][column] == KING))
				{
					if(gameBoard[row][0] == NONE)
					{
						moveFound = true;
	
						fromRow = row - 1;
						fromColumn = 1;
						toRow = row;
						toColumn = 0;
					}
					else if (column == 6 && gameBoard[row][7] == NONE)
					{
	                   	moveFound = true;
	
						fromRow = row - 1;
						fromColumn = 6;
						toRow = row;
						toColumn = 7;
					}
				}
			}
		}
	}
	if( !moveFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}
void male3Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn, int& Moves )
{
	bool jumpFound = false;
	for (int column=0; column <BOARD_SIZE; column++)
	{
		if (gameBoard[4][column]=FEMALE && !jumpFound)
		{
			if (column==4 
				&& gameBoard[2][1]==MALE
				&& gameBoard[3][2]==' ')
			{
				fromRow = 2;
				fromColumn = 1; 
				toRow = 3;
				toColumn = 2;
				jumpFound = true;
			}
			if (column == 7
				&& gameBoard[2][5]==MALE
				&& gameBoard[3][6]==' '
				&& gameBoard[2][7]==MALE)
			{
				fromRow = 2;
				fromColumn = 7; 
				toRow = 3;
				toColumn = 6;
				jumpFound = true;
			}
			if ((column == 5
				&& gameBoard[2][5]==MALE
				&& gameBoard[2][7]==MALE
				&& gameBoard[3][6]==' '))
			{	
				if (gameBoard[4][7]==FEMALE)
				{
					fromRow = 2;
					fromColumn = 5; 
					toRow = 3;
					toColumn = 4;
					jumpFound = true;
				}
				if(gameBoard[4][7]==' ')
				{
					fromRow = 2;
					fromColumn = 5; 
					toRow = 3;
					toColumn = 6;
					jumpFound = true;
				}
			}
			if (column==3
				&&gameBoard[2][3]==MALE)
			{
				if(gameBoard[5][2]==' '
					&& gameBoard[3][4]==' ')
				{
					fromRow = 2;
					fromColumn = 3; 
					toRow = 3;
					toColumn = 4;
					jumpFound = true;

				}
				if(gameBoard[4][5]==' '
					&& gameBoard[3][2])
				{
					fromRow = 2;
					fromColumn = 3; 
					toRow = 3;
					toColumn = 2;
					jumpFound = true;
				}
			}
			if (column==3
				&&gameBoard[3][4]==MALE
				&& gameBoard[5][2]==' '
				&& gameBoard[1][6]==' '
				&& gameBoard[3][0]==MALE
				&& gameBoard[6][3]==FEMALE)
			{
				fromRow = 3;
				fromColumn = 4; 
				toRow = 5;
				toColumn = 2;
				jumpFound = true;
			}
		}
	}
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == KING )
			{
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE 
					&& !jumpFound)
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE 
					&& !jumpFound )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE 
					&& gameBoard[row - 3][column + 3] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) 
					&& gameBoard[row + 2][column + 2] == NONE 
					&& gameBoard[row + 3][column + 3] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}		
				//jump down and left
			if( column > 1 && 
				spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
				gameBoard[row - 1][column + 1] == NONE && 
				gameBoard[row + 2][column - 2] == NONE
				&& !jumpFound)
			{
				jumpFound = true;
				fromRow = row;
				fromColumn = column; 
				toRow = row + 2;
				toColumn = column - 2;
			}
			if( column > 1 && 
				spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
				gameBoard[row - 1][column + 1] == NONE &&( 
				gameBoard[row + 2][column - 2] == FEMALE||
				gameBoard[row + 2][column - 2] == MALE)
				&& !jumpFound)
			{

			}
			//Defense against Female Up and Left
			if( column < 6 && row>=2 &&
				spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
				gameBoard[row - 1][column - 1] == ' ' && 
				gameBoard[row + 2][column + 2] == FEMALE)
			{
				if (gameBoard[row-2][column]==MALE)
				{
					fromRow = row-2;
					fromColumn = column; 
					toRow = row-1;
					toColumn = column-1;
					jumpFound=true;
				}
				if(gameBoard[row-2][column-2]==MALE)
				{
					fromRow = row-2;
					fromColumn = column-2; 
					toRow = row-1;
					toColumn = column-1;
					jumpFound=true;
				}
			}
			//Defense Against Female Up and Right
			if( column < 6 && row>=2 &&
				spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
				gameBoard[row - 1][column + 1] == NONE && 
				gameBoard[row+2][column-2]==FEMALE)
			{
				if (gameBoard[row-2][column]==MALE)
				{
					fromRow = row-2;
					fromColumn = column; 
					toRow = row-1;
					toColumn = column+1;
					jumpFound=true;
				}
				if(gameBoard[row-2][column+2]==MALE)
				{
					fromRow = row-2;
					fromColumn = column+2; 
					toRow = row-1;
					toColumn = column+1;
					jumpFound=true;
				}
			}
		}	
	}
	if (Moves == 1 && !jumpFound)
	{
		fromRow = 2;
		fromColumn = 1; 
		toRow = 3;
		toColumn = 1;
		jumpFound=true;
	}
	if (Moves == 2 && !jumpFound)
	{
		fromRow = 2;
		fromColumn = 5; 
		toRow = 3;
		toColumn = 6;
		jumpFound=true;
	}
	if (Moves==3 && !jumpFound && gameBoard[2][5]==' ')
	{
		fromRow = 1;
		fromColumn = 6; 
		toRow = 2;
		toColumn = 5;
		jumpFound=true;
	}
	if (Moves==4 && !jumpFound && gameBoard[1][2]==' ')
	{
		fromRow = 1;
		fromColumn = 0; 
		toRow = 1;
		toColumn = 2;
		jumpFound=true;
	}
	if (Moves==4 && !jumpFound && gameBoard[1][2]==' ')
	{
		fromRow = 1;
		fromColumn = 0; 
		toRow = 1;
		toColumn = 2;
		jumpFound=true;
	}

	if( !jumpFound)
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
	
}

//prototype
void male4Block(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn, bool& block );

//main function
void male4Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	bool jumpOverQueen = false;
	bool jumpToKing = false;
	bool block = false;

	male4Block(gameBoard, fromRow, toRow, fromColumn, toColumn, block );

	for(int row = 0; row < BOARD_SIZE && !jumpToKing && !jumpOverQueen && !block; row++)
	{
		for(int column = 0; column < BOARD_SIZE && !jumpToKing && !jumpOverQueen && !block; column++)
		{
			if( gameBoard[row][column] == KING )
			{
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
					if(spotHasPlayersPiece( gameBoard, QUEEN, row - 1, column - 1 ))
					{
						jumpOverQueen = true;
					}
					if(toRow == 7)
					{
						jumpToKing = true;
					}
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE)
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
					if(spotHasPlayersPiece( gameBoard, QUEEN, row - 1, column + 1 ))
					{
						jumpOverQueen = true;
					}
					if(toRow == 7)
					{
						jumpToKing = true;
					}
				}
			}
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
					if(spotHasPlayersPiece( gameBoard, QUEEN, row + 1, column - 1 ))
					{
						jumpOverQueen = true;
					}
					if(toRow == 7)
					{
						jumpToKing = true;
					}
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
					if(spotHasPlayersPiece( gameBoard, QUEEN, row + 1, column + 1 ))
					{
						jumpOverQueen = true;
					}
					if(toRow == 7)
					{
						jumpToKing = true;
					}
				}
			}
		}	
	}

	bool makeKing = false;

	for(int row = 0; row < BOARD_SIZE && !jumpFound && !makeKing; row++)
	{
		for(int column = 0; column < BOARD_SIZE && !jumpFound && !makeKing; column++)
		{
			if( gameBoard[row][column] == MALE )
			{
				if ( column == 6 && 
						spotHasPlayersPiece( gameBoard, MALE, row, column ) &&
						gameBoard[row + 1][column - 1] == NONE)
					{
						makeKing = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column - 1;
					}
					if ( column == 6 && 
						spotHasPlayersPiece( gameBoard, MALE, row, column ) &&
						gameBoard[row + 1][column + 1] == NONE)
					{
						makeKing = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column + 1;
					}
			}
		}
	}

	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE && !jumpFound; column++)
		{
			if( gameBoard[row][column] == MALE )
			{
				if ( column < 4 && 
						spotHasPlayersPiece( gameBoard, MALE, row, column ) &&
						gameBoard[row + 1][column - 1] == NONE &&
                        gameBoard[row + 2][column - 2] == NONE &&
						(gameBoard[row + 2][column] == NONE ||
						 gameBoard[row][column - 2] == MALE))
					{
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column - 1;
					}
					if ( column > 4 && 
						spotHasPlayersPiece( gameBoard, MALE, row, column ) &&
						gameBoard[row + 1][column + 1] == NONE &&
                        gameBoard[row + 2][column + 2] == NONE &&
						(gameBoard[row + 2][column] == NONE ||
						 gameBoard[row][column + 2] == MALE))
					{
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column + 1;
					}
			}
		}
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}

//other function
void male4Block(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn, bool& block )
{
	for(int row = 0; row < BOARD_SIZE; row++)
		{
			for(int column = 0; column < BOARD_SIZE; column++)
			{
				if( gameBoard[row][column] == KING )
				{
					//block up and left
					if( column > 1 && 
						spotHasPlayersPiece( gameBoard, MALE, row - 2, column - 2 ) &&
						(spotHasPlayersPiece( gameBoard, FEMALE, row - 3, column - 3 ) ||
						 spotHasPlayersPiece( gameBoard, QUEEN, row - 3, column - 3 )))
					{
						fromRow = row;
						fromColumn = column; 
						toRow = row - 1;
						toColumn = column - 1;
					}
					//block up and right
					if( column < 6 && 
						spotHasPlayersPiece( gameBoard, MALE, row - 2, column + 2 ) &&
						(spotHasPlayersPiece( gameBoard, FEMALE, row - 3, column + 3 ) ||
						 spotHasPlayersPiece( gameBoard, QUEEN, row - 3, column + 3 )))
					{
						fromRow = row;
						fromColumn = column; 
						toRow = row - 1;
						toColumn = column + 1;
					}
				}
				if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
				{		
					//block down and left
					if( column > 1 && 
						spotHasPlayersPiece( gameBoard, MALE, row + 2, column - 2 ) &&
						(spotHasPlayersPiece( gameBoard, FEMALE, row + 3, column - 3 ) ||
						 spotHasPlayersPiece( gameBoard, QUEEN, row + 3, column - 3 )))
					{
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column - 1;
					}
					//jump down and right
					if( column < 6 && 
						spotHasPlayersPiece( gameBoard, MALE, row + 2, column + 2 ) &&
						(spotHasPlayersPiece( gameBoard, FEMALE, row + 3, column + 3 ) ||
						 spotHasPlayersPiece( gameBoard, QUEEN, row + 3, column + 3 )))
					{
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column + 1;
					}
				}
			}	
		}
}


void male5Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			
			if( gameBoard[row][column] == KING )
			{
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				 
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				if(column > 1 && spotHasPlayersPiece( gameBoard, FEMALE, row + 3, column - 3))
				{	
					jumpFound = false;

					
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
				if(column > 1 && spotHasPlayersPiece( gameBoard, FEMALE, row + 3, column + 3))
				{	
					jumpFound = false;

					
				}
			}
		}	
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}
void male6Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	bool continueTesting = true;
		
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{	
				if( column > 0 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && continueTesting == true)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				if( column < 5 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE && continueTesting == true )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
		}
	}

	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{	
				if( column > 0 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column] != NONE && continueTesting == true &&
					gameBoard[row][column - 2] != NONE && gameBoard[row + 2][column - 2] != FEMALE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column - 1;
				}

				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column] != NONE && continueTesting == true &&
					gameBoard[row][column + 2] != NONE && gameBoard[row + 2][column + 2] != FEMALE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column + 1;
				}
			}
		}
	}
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{	
				if( column == 1 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column] == FEMALE && continueTesting == true)
				{
					jumpFound = true;
					continueTesting = false;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column - 1;
				}

				if( column == 6 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column] == FEMALE && continueTesting == true)
				{
					jumpFound = true;
					continueTesting = false;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column + 1;
				}

				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column] == FEMALE && continueTesting == true &&
					gameBoard[row][column - 2] == NONE)
				{
					continueTesting = false;
				}

				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column] == FEMALE && continueTesting == true &&
					gameBoard[row][column + 2] == NONE)
				{
					continueTesting = false;
				}


				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == FEMALE && continueTesting == true)
				{
					continueTesting = false;
				}

				if( 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == FEMALE && continueTesting == true)
				{
					continueTesting = false;
				}
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == MALE && continueTesting == true)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column - 1;
				}

				if( column <6 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == MALE && continueTesting == true) 
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column + 1;
				}

				if( column < 7 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 2, column ) &&
					gameBoard[row + 1][column + 1] == NONE && continueTesting == true )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column + 1;
				}

				if( column > 0 && 
					spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column] == MALE && continueTesting == true )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 1;
					toColumn = column - 1;
				}

			if( gameBoard[row][column] == KING )
			{

				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE && continueTesting == true )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}

				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE && continueTesting == true )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
		}	
	}
}
	//for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	//{
	//	for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
	//	{
	//			if(	spotHasPlayersPiece( gameBoard, FEMALE, row, column))
	//			{
	//				gameBoard[row][column] = NONE;
	//			}
	//	}
	//}

if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}



void male7Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, 
int& fromColumn, int& toColumn )
{
	bool moveFound = false;

	for(int row = 0; row < BOARD_SIZE && !moveFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !moveFound; column++)
		{
		//safe move for downright
		if( gameBoard[row][column] == MALE )
		{	
			if (gameBoard[row + 1][column + 1] == NONE && 
			    gameBoard[row + 2][column + 2] != FEMALE && 
				gameBoard[row + 2][column + 2] != QUEEN &&
			    gameBoard[row + 2][column] != FEMALE &&
				gameBoard[row + 2][column] != QUEEN)
			{
				moveFound = true;
				fromRow = row;
				fromColumn = column; 
				toRow = row + 1;
				toColumn = column + 1;
			}
			//safe move for downleft
			if (gameBoard[row + 1][column - 1] == NONE && 
			     gameBoard[row + 2][column - 2] != FEMALE && 
				 gameBoard[row + 2][column - 2] != QUEEN &&
			     gameBoard[row + 2][column] != FEMALE &&
				 gameBoard[row + 2][column] != QUEEN)
			{
				moveFound = true;
				fromRow = row;
				fromColumn = column; 
				toRow = row + 1;
				toColumn = column - 1;
			}
		}
		//downright to back up
		if( gameBoard[row][column] == MALE )
		{
			if ( gameBoard[row + 2][column + 2] == MALE && gameBoard[row + 
2][column] == MALE
				&& gameBoard[row + 1][column + 1] == NONE)
			{
				moveFound = true;
				fromRow = row;
				fromColumn = column; 
				toRow = row + 1;
				toColumn = column + 1;
			}
			//downleft to backup
			if ( gameBoard[row + 2][column - 2] == MALE && gameBoard[row + 
2][column] == MALE
				&& gameBoard[row + 1][column - 1] == NONE )
			{
				moveFound = true;
				fromRow = row;
				fromColumn = column; 
				toRow = row + 1;
				toColumn = column - 1;
			}
		}


			if( gameBoard[row][column] == MALE )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE )

					{
						moveFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column - 2;
					}
					
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
					{
						moveFound = true;

						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column + 2;
					}
				}
			}

			if( gameBoard[row][column] == KING )
			{
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && 
				    gameBoard[row + 3][column - 3] != FEMALE && 
					gameBoard[row + 3][column - 3] != QUEEN && 
				    gameBoard[row + 3][column - 1] != FEMALE &&
					gameBoard[row + 3][column - 1] != QUEEN )

					{
						moveFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column - 2;
					}
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE &&
				    gameBoard[row + 3][column + 3] != FEMALE && 
					gameBoard[row + 3][column + 3] != QUEEN &&
				    gameBoard[row + 3][column + 1] != FEMALE &&
					gameBoard[row + 3][column + 1] != QUEEN)
					{
						moveFound = true;

						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column + 2;
					}
				}

				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE && 
					gameBoard[row - 1][column - 3] != FEMALE &&
					gameBoard[row - 1][column - 3] != QUEEN)
				{
					
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
					
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE &&
					gameBoard[row + 1][column + 3] != FEMALE &&
					gameBoard[row + 1][column + 3] != QUEEN)
				{
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}

			if( gameBoard[row][column] == MALE )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && 
				   (gameBoard[row + 3][column - 3] == FEMALE || 
				    gameBoard[row + 3][column - 3] == QUEEN ||
				    gameBoard[row + 3][column - 1] == FEMALE ||
					gameBoard[row + 3][column - 1] == QUEEN )&&
					gameBoard[row][column - 2] == MALE )

					{
						moveFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column - 2;
					}
					
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE &&
				   (gameBoard[row + 3][column + 3] == FEMALE || 
				    gameBoard[row + 3][column + 3] == QUEEN ||
				    gameBoard[row + 3][column + 1] == FEMALE ||
					gameBoard[row + 3][column + 1] == QUEEN) &&
					gameBoard[row][column + 2] == MALE)
					{
						moveFound = true;

						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column + 2;
					}
				}
			}

			if( gameBoard[row][column] == KING )
			{
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && 
				   (gameBoard[row + 3][column - 3] == FEMALE || 
				    gameBoard[row + 3][column - 3] == QUEEN || 
				    gameBoard[row + 3][column - 1] == FEMALE ||
					gameBoard[row + 3][column - 1] == QUEEN) &&
					gameBoard[row][column - 2] == MALE)

					{
						moveFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column - 2;
					}
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE &&
				   (gameBoard[row + 3][column + 3] == FEMALE || 
					gameBoard[row + 3][column + 3] == QUEEN ||
				    gameBoard[row + 3][column + 1] == FEMALE ||
					gameBoard[row + 3][column + 1] == QUEEN) &&
					gameBoard[row][column + 2] == MALE)
					{
						moveFound = true;

						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column + 2;
					}
				}

				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE && 
				   (gameBoard[row - 1][column - 3] == FEMALE ||
				    gameBoard[row - 1][column - 3] == QUEEN)&&
				   (gameBoard[row - 4][column] == MALE || 
				    gameBoard[row - 4][column - 2] == MALE))
				{
					
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
					
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE &&
				   (gameBoard[row - 1][column + 3] == FEMALE ||
				    gameBoard[row - 1][column + 3] == QUEEN )&&
				   (gameBoard[row - 4][column] == MALE || 
					gameBoard[row - 4][column + 2] == MALE))
				{
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}

			if( gameBoard[row][column] == MALE )
			{		
				//jump down and left to edge
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && column == 1 )
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right to edge
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE &&  column == 7 )
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}

			//jump down and left to edge
			if( gameBoard[row][column] == KING )
			{
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && column == 1)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right to edge
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE && column == 7 )
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}

				//jump up and left to edge
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE && column == 1 )
				{
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right to edge
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE && column == 7 )
				{
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}

			if( gameBoard[row][column] == MALE )
			{		
				//jump down and left free
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && 
				    gameBoard[row + 3][column - 3] != FEMALE && 
					gameBoard[row + 3][column - 3] != QUEEN &&
					gameBoard[row + 3][column - 1] != FEMALE &&
					gameBoard[row + 3][column - 1] != QUEEN )
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right free
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE && 
				    gameBoard[row + 3][column + 3] != FEMALE && 
					gameBoard[row + 3][column + 3] != QUEEN &&
					gameBoard[row + 3][column + 1] != FEMALE &&
					gameBoard[row + 3][column + 1] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}

			if( gameBoard[row][column] == KING )
			{
				//jump down and left free
				if(column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && 
				    gameBoard[row + 3][column - 3] != FEMALE &&
					gameBoard[row + 3][column - 3] != QUEEN &&
				    gameBoard[row + 3][column - 1] != FEMALE &&
					gameBoard[row + 3][column - 1] != QUEEN)
				{
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right free
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE && 
				    gameBoard[row + 3][column + 3] != FEMALE && 
					gameBoard[row + 3][column + 3] != QUEEN && 
				    gameBoard[row + 3][column + 1]!= FEMALE &&
					gameBoard[row + 3][column + 1]!= QUEEN )
				{ 
					moveFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}

				//jump up and left free
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE && 
				    gameBoard[row - 1][column - 3] != FEMALE &&
					gameBoard[row - 1][column - 3] != QUEEN )
				{
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right free
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE && 
					gameBoard[row - 1][column + 3] != FEMALE &&
					gameBoard[row - 1][column + 3] != QUEEN )
				{
					moveFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
		}			
	}

	if ( !moveFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}
void male8Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == KING )
			{
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == MALE || gameBoard[row][column] == KING )
			{		
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, FEMALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
		}	
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}
void maleRandomMove(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}

void female1Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	bool blockFound = false;
	bool rightMoveFound = false;
	bool leftMoveFound = false;
	for(int row = BOARD_SIZE - 1; row >= 0 && !jumpFound; row--)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == QUEEN )
			{
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
			}
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{		
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
		}	
	}
	if( !jumpFound )
	{
		for(int row = BOARD_SIZE - 1; row >= 0 && !jumpFound; row--)
		{
			for(int column = 0; column < BOARD_SIZE  && !blockFound; column++)
			{
				if( gameBoard[row][column] == QUEEN )
				{
					//block down and right
					if( column < 6 && 
						spotHasPlayersPiece( gameBoard, FEMALE, row + 2, column + 2 ) &&
						gameBoard[row + 1][column + 1] == NONE )
					{
						blockFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column + 1;
					}
					//block down and left
					if( column > 1 && 
						spotHasPlayersPiece( gameBoard, FEMALE, row + 2, column - 2 ) &&
						gameBoard[row + 1][column - 1] == NONE )
					{
						blockFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 1;
						toColumn = column - 1;
					}
				}
				if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN  )
				{		
					//block up and left
					if( column > 1 && 
						spotHasPlayersPiece( gameBoard, FEMALE, row - 2, column - 2 ) &&
						gameBoard[row - 1][column - 1] == NONE)
					{
						blockFound = true;

						fromRow = row;
						fromColumn = column; 
						toRow = row - 1;
						toColumn = column - 1;
					}
					//block up and right
					if( column < 6 && 
						spotHasPlayersPiece( gameBoard, FEMALE, row - 2, column + 2 ) &&
						gameBoard[row - 1][column + 1] == NONE )
					{
						blockFound = true;

						fromRow = row;
						fromColumn = column; 
						toRow = row - 1;
						toColumn = column + 1;
					}
				}
			}	
		}
	}
	if ( !jumpFound && !blockFound )
	{
		for(int row = BOARD_SIZE - 1; row >= 0 && !leftMoveFound; row--)
		{
			for(int column = 0; column < BOARD_SIZE  && !leftMoveFound; column++)
			{
				//move up and left
				fromColumn = column;
				toColumn = column - 1;
				fromRow = row;
				toRow = row - 1;
				leftMoveFound = validMove(fromColumn, toColumn, fromRow, toRow, FEMALE, gameBoard);
			}
		}
	}
	if ( !jumpFound && !blockFound && !leftMoveFound )
	{
		for(int row = BOARD_SIZE - 1; row >= 0 && !rightMoveFound; row--)
		{
			for(int column = 0; column < BOARD_SIZE  && !rightMoveFound; column++)
			{
				//move up and right
				fromColumn = column;
				toColumn = column + 1;
				fromRow = row;
				toRow = row - 1;
				rightMoveFound = validMove(fromColumn, toColumn, fromRow, toRow, FEMALE, gameBoard);
			}
		}
	}
	if ( !jumpFound && !blockFound && !rightMoveFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}

void female2Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == QUEEN )
			{
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{		
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
					
					if ( column > 1 && spotHasPlayersPiece( gameBoard, MALE, row - 3, column - 3 ) &&
						gameBoard[row - 4][column - 4] == NONE)
					{
						
						
						if( spotHasPlayersPiece( gameBoard, MALE, row - 5, column - 5 ) && 
							gameBoard[row - 4][column - 4] == NONE)
						{
							jumpFound = false;
						}
						else
						{	
							jumpFound = true;
							fromRow = row;
							fromColumn = column; 
							toRow = row - 4;
							toColumn = column - 4;
						}
					}
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
					
					if( column > 6 && spotHasPlayersPiece( gameBoard, MALE, row - 3, column + 3 ) &&
						gameBoard[row - 4][column + 4] == NONE)
					{
						if( !spotHasPlayersPiece( gameBoard, MALE, row - 5, column + 5 ))
						{
							jumpFound = true;
							fromRow = row;
							fromColumn = column; 
							toRow = row - 4;
							toColumn = column + 4;
						}
						else
						{	
							jumpFound = false;
						}
					}
				}
			}
		}	
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}

void female3Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == QUEEN )
			{
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{		
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
		}	
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
	//cout << "///GIRLS RULE!!!\\\\\\" << endl;
}
void female4Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool jumpFound = false;
	for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
		{
			if( gameBoard[row][column] == QUEEN )
			{
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE && !spotHasPlayersPiece (gameBoard, MALE, row - 3, column - 1) && !spotHasPlayersPiece (gameBoard, MALE, row - 3, column - 3))
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE && !spotHasPlayersPiece (gameBoard, MALE, row - 3, column + 1) && !spotHasPlayersPiece (gameBoard, MALE, row - 3, column + 3))
				{
					jumpFound = true;
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == FEMALE )
			{		
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
			if( gameBoard[row][column] == QUEEN )
			{		
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE && !spotHasPlayersPiece( gameBoard, MALE, row + 3, column + 1) && !spotHasPlayersPiece( gameBoard, MALE, row - 3, column - 3))
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE && !spotHasPlayersPiece( gameBoard, MALE, row + 3, column + 1) && !spotHasPlayersPiece( gameBoard, MALE, row + 3, column + 3))
				{
					jumpFound = true;

					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
				}
			}
		}	
	}

	if( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}

void female5Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}

void female6OutsideMove (int fromRow, int toRow, int fromColumn, int toColumn, int& oRow, int& oColumn, bool& outsideJump )
{
	if ( toColumn == 0 || toColumn == 7 || toRow == 0 || toColumn == 7)
	{
		outsideJump = true;
		oRow = toRow;
		oColumn = toColumn;
	}
}

// carson copeland
void female6Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn)
{
	bool jumpFound = false;
	bool takeMove = true;
	bool outsideJump = false;
	int oRow = 0;
	int oColumn = 0;
	for(int row = 0; row < BOARD_SIZE && !outsideJump; row++)
	{
		for(int column = 0; column < BOARD_SIZE  && !outsideJump; column++)
		{
			if( gameBoard[row][column] == QUEEN )
			{
				//jump down and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column - 1 ) &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column - 2;
					if ( gameBoard[toRow + 1][toColumn - 1] != MALE || gameBoard[toRow + 1][toColumn - 1] != KING  )
					{
						jumpFound = true;
						female6OutsideMove (fromRow, toRow, fromColumn, toColumn, oRow, oColumn, outsideJump );
					}
				}
				//jump down and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row + 1, column + 1 ) &&
					gameBoard[row + 2][column + 2] == NONE )
				{
					
					fromRow = row;
					fromColumn = column; 
					toRow = row + 2;
					toColumn = column + 2;
					if ( gameBoard[toRow + 1][toColumn + 1] != MALE || gameBoard[toRow + 1][toColumn + 1] != KING )
					{
						jumpFound = true;
						female6OutsideMove (fromRow, toRow, fromColumn, toColumn, oRow, oColumn, outsideJump );
					}
				}
			}
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{		
				//jump up and left
				if( column > 1 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
					gameBoard[row - 2][column - 2] == NONE)
				{
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column - 2;
					if ( gameBoard[toRow - 1][toColumn - 1] != MALE || gameBoard[toRow - 1][toColumn - 1] != KING )
					{
						jumpFound = true;
						female6OutsideMove (fromRow, toRow, fromColumn, toColumn, oRow, oColumn, outsideJump );
					}
				}
				//jump up and right
				if( column < 6 && 
					spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
					gameBoard[row - 2][column + 2] == NONE )
				{
					fromRow = row;
					fromColumn = column; 
					toRow = row - 2;
					toColumn = column + 2;
					if ( gameBoard[toRow - 1][toColumn + 1] != MALE || gameBoard[toRow - 1][toColumn + 1] != KING )
					{
						jumpFound = true;
						female6OutsideMove (fromRow, toRow, fromColumn, toColumn, oRow, oColumn, outsideJump );
					}
				}
			}
		}	
	}
	if ( outsideJump )
	{
		toRow = oRow;
		toColumn = oColumn;
	}
	if ( !jumpFound )
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}
}



// Austin Kelly				9:00 Steil				Checkers.cpp
void female7Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	//bool jumpFound = false; 
	//bool safeMove = false;
	//bool safeRandomMove = false;
	//int safeRow = 0;
	//int safeColumn = 0;
	//int count = 1;
	////Records Last Safe Jump Found
	//for(int row = 0; row < BOARD_SIZE && !jumpFound; row++)
	//{
	//	for(int column = 0; column < BOARD_SIZE  && !jumpFound; column++)
	//	{
	//		if( gameBoard[row][column] == QUEEN )
	//		{
	//			//jump down and left
	//			if( column > 1 && 
	//				spotHasPlayersPiece( gameBoard, MALE, row + 1, column - 1 ) &&
	//				gameBoard[row + 2][column - 2] == NONE && ( gameBoard[toRow + 1][toColumn - 1] != MALE ||
	//				gameBoard[row + 3][column - 3] != KING ) )
	//			{
	//				jumpFound = true;
	//				fromRow = row;
	//				fromColumn = column; 
	//				toRow = row + 2;
	//				toColumn = column - 2;	
	//			}
	//			//jump down and right
	//			if( column < 6 && 
	//				spotHasPlayersPiece( gameBoard, MALE, row + 1, column + 1 ) &&
	//				gameBoard[row + 2][column + 2] == NONE && ( gameBoard[toRow + 1][toColumn + 1] != MALE ||
	//				gameBoard[row + 3][column + 3] != KING ) )
	//			{
	//				jumpFound = true;
	//				fromRow = row;
	//				fromColumn = column; 
	//				toRow = row + 2;
	//				toColumn = column + 2;
	//			}
	//		}
	//		if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
	//		{		
	//			//jump up and left
	//			if( column > 1 && 
	//				spotHasPlayersPiece( gameBoard, MALE, row - 1, column - 1 ) &&
	//				gameBoard[row - 2][column - 2] == NONE && ( gameBoard[toRow - 1][toColumn - 1] != MALE ||
	//				gameBoard[row - 3][column - 3] != KING ))
	//			{
	//				jumpFound = true;
	//				fromRow = row;
	//				fromColumn = column; 
	//				toRow = row - 2;
	//				toColumn = column - 2;
	//			}
	//			//jump up and right
	//			if( column < 6 && 
	//				spotHasPlayersPiece( gameBoard, MALE, row - 1, column + 1 ) &&
	//				gameBoard[row - 2][column + 2] == NONE && ( gameBoard[toRow - 1][toColumn + 1] != MALE ||
	//				gameBoard[row - 3][column + 3] != KING ) )
	//			{
	//				jumpFound = true;
	//				fromRow = row;
	//				fromColumn = column; 
	//				toRow = row - 2;
	//				toColumn = column + 2;
	//			}
	//		}
	//	}	
	//}

	//if( !jumpFound )
	//{
	//	//Prioritize ALL safe moves
	//	for(int row = 0; row < BOARD_SIZE && !safeMove; row++)
	//	{
	//		for(int column = 0; column < BOARD_SIZE && !safeMove; column++)
	//		{
	//			if ( column == 6 && spotHasPlayersPiece( gameBoard, NONE, row - 1, column + 1))
	//			{
	//				toRow = row - 1;
	//				toColumn = column + 1;
	//				safeMove = true;
	//			}
	//			if ( column == 6 && spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1))
	//			{
	//				toRow = row + 1;
	//				toColumn = column + 1;
	//				safeMove = true;
	//			}
	//			if ( column == 1 && spotHasPlayersPiece( gameBoard, NONE, row - 1, column - 1))
	//			{
	//				toRow = row - 1;
	//				toColumn = column - 1;
	//				safeMove = true;
	//			}
	//			if ( column == 1 && spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1))
	//			{
	//				toRow = row + 1;
	//				toColumn = column - 1;
	//				safeMove = true;
	//			}
	//			if ( row == 1 && spotHasPlayersPiece( gameBoard, NONE, row - 1, column + 1))
	//			{
	//				toRow = row - 1;
	//				toColumn = column + 1;
	//				safeMove = true;
	//			}
	//			if ( row == 1 && spotHasPlayersPiece( gameBoard, NONE, row - 1, column - 1))
	//			{
	//				toRow = row - 1;
	//				toColumn = column - 1;
	//				safeMove = true;
	//			}
	//			if ( row == 6 && spotHasPlayersPiece( gameBoard, NONE, row + 1, column + 1))
	//			{
	//				toRow = row + 1;
	//				toColumn = column + 1;
	//				safeMove = true;
	//			}
	//			if ( row == 6 && spotHasPlayersPiece( gameBoard, NONE, row + 1, column - 1))
	//			{
	//				toRow = row + 1;
	//				toColumn = column - 1;
	//				safeMove = true;
	//			}
	//		}
	//	}
	//}
	//if ( !safeMove )
	//{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	////}
}

//*******************************************************

bool female8isMoveSafeLeft(char gameBoard[][BOARD_SIZE], int fromRow, int toRow, int fromColumn, int toColumn, int row ,int column );
bool female8isMoveSafeRight(char gameBoard[][BOARD_SIZE], int fromRow, int toRow, int fromColumn, int toColumn, int row ,int column );


//******************************************************



void female8Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	bool SafeMove = false;
	bool jumpFound = false;
	for(int row =  0 ; row < BOARD_SIZE && !SafeMove; row++)
	{
		for(int column =0  ; column < BOARD_SIZE  && !SafeMove; column++ )
		{				
			if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
			{
//***---***
				if( gameBoard[row][column] == QUEEN )
				{
					//jump down and RIGHT
					if( ( column <= 5 && row <=5 ) 
						&& (gameBoard[row +1 ][column +1 ]== MALE || gameBoard[row +1 ][column +1]== KING )
						&& gameBoard[row + 2][column + 2] == NONE )
					{
						jumpFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column + 2;
					}
					
					//jump down and LEFT
					else if( (column >=2 && row <=5 )
						&& (gameBoard[row +1 ][column -1 ]== MALE || gameBoard[row +1 ][column -1]== KING )
						&&  gameBoard[row + 2][column -2 ] == NONE )
					{
						jumpFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row + 2;
						toColumn = column - 2;
					}
				}
					
				if( gameBoard[row][column] == FEMALE || gameBoard[row][column] == QUEEN )
				{		
					//jump up and left
					if( ( row >= 2 && column >= 2 )
						&&(gameBoard[row -1 ][column -1 ]== MALE || gameBoard[row -1 ][column -1]== KING )
						&& gameBoard[row -2][column -2] == NONE)
					{
						jumpFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row - 2;
						toColumn = column - 2;
					}

					//jump up and right
					else if( ( row >=2  && column <= 5 )
						&&(gameBoard[row -1 ][column +1 ]== MALE || gameBoard[row -1 ][column +1]== KING )
						&& gameBoard[row -2][column +2] == NONE)
					{
						jumpFound = true;
						fromRow = row;
						fromColumn = column; 
						toRow = row - 2;
						toColumn = column + 2;
					}
				}
			}
		}
	}
		
			


//***---***
				if( !jumpFound)
				{
					for(int row =  0 ; row < BOARD_SIZE && !SafeMove; row++)
					{
						for(int column =0  ; column < BOARD_SIZE  && !SafeMove; column++ )
						{
							if( gameBoard[row][column] == FEMALE)
							{	//move to the  LEFT
								if ( female8isMoveSafeLeft(gameBoard, fromRow, toRow, fromColumn, toColumn, row , column ) )
								{
									SafeMove = true;
									fromRow = row;
									fromColumn = column; 
									toRow = row -1;
									toColumn = column - 1;
								}
					
								//move  move to RIGHT
								else if ( female8isMoveSafeRight(gameBoard, fromRow, toRow, fromColumn, toColumn, row , column ))
								{
									SafeMove = true;
									fromRow = row;
									fromColumn = column; 
									toRow = row -1;
									toColumn = column + 1;
								}
							}
						}
					}
				}


	if (!(SafeMove || jumpFound))
	{
		getRandomMove(fromRow, toRow, fromColumn, toColumn);
	}

}

bool female8isMoveSafeLeft(char gameBoard[][BOARD_SIZE], int fromRow, int toRow, int fromColumn, int toColumn, int row ,int column )
{
	bool result = false;
	if( gameBoard[row - 1][column - 1] == NONE)
	{
		if(  (  row == 1 && column >=2   )
				|| ( row >= 2 && column == 1 )  
				|| ( column >1 && gameBoard[row - 2][column - 2]!= MALE && gameBoard[row - 2][column]!= MALE) 
				|| ( column >1 && gameBoard[row - 2][column - 2]== NONE && gameBoard[row - 2][column]!= NONE 
				&&  gameBoard[row ][column - 2]!= NONE ))
		{
			result = true;
		}
	}	
			
	return result;
}

bool female8isMoveSafeRight(char gameBoard[][BOARD_SIZE], int fromRow, int toRow, int fromColumn, int toColumn, int row ,int column )
{
	bool result = false;
	if (gameBoard[row - 1][column + 1] == NONE)
	{
		if (	(row == 1  && column <=6  )  
						|| ( row >= 2 && column == 6  )  
						|| ( column <=5 && gameBoard[row - 2][column + 2]!= MALE && gameBoard[row - 2][column ]!= MALE) 
						|| ( column <=5 && gameBoard[row - 2][column + 2]== NONE && gameBoard[row - 2][column ]!= NONE 
						&&  gameBoard[row ][column +2]!= NONE ) )
		{
			result = true;
		}
	}
	return result;
}
//******************************************************


void femaleRandomMove(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}


