//not sure what to do with this.

#include<iostream>
#include<time.h>
#include<cstdlib>

using std::cout;
using std::cin;
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
void male3Move( char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn );
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

	do
	{
		if( player == MALE )
		{
			switch(malePlayer)
			{
				case 1:	male1Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 2:	male2Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 3:	male3Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 4:	male4Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 5:	male5Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 6:	male6Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 7:	male7Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 8:	male8Move(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
				case 9:	maleRandomMove(gameBoard, fromRow, toRow, fromColumn, toColumn); break;
			}
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
					gameBoard[row + 1][column - 1] == FEMALE &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				//can jump down and right
				if( column < 6 && 
					gameBoard[row + 1][column + 1] == FEMALE &&
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
					gameBoard[row - 1][column - 1] == FEMALE &&
					gameBoard[row - 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				//can jump up and right
				if( column < 6 && 
					gameBoard[row - 1][column + 1] == FEMALE &&
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
					gameBoard[row - 1][column - 1] == MALE &&
					gameBoard[row - 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				if( column < 6 && 
					gameBoard[row - 1][column + 1] == MALE &&
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
					gameBoard[row + 1][column - 1] == MALE &&
					gameBoard[row + 2][column - 2] == NONE )
				{
					moveFound = true;
				}
				if( column < 6 && 
					gameBoard[row + 1][column + 1] == MALE &&
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
void male2Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void male3Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void male4Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void male5Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void male6Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void male7Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
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
}
void female2Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void female3Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void female4Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void female5Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void female6Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void female7Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void female8Move(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}
void femaleRandomMove(char gameBoard[][BOARD_SIZE], int& fromRow, int& toRow, int& fromColumn, int& toColumn )
{
	getRandomMove(fromRow, toRow, fromColumn, toColumn);
}

