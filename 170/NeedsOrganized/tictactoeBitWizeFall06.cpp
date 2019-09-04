#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

void main()
{
	//1|2|3
	//4|5|6
	//7|8|9

	//win conditions
	//14,112,896,164,292,584,546,168

	int xMoves = 0;
	int oMoves = 0;
	char turn = 'X';

	bool xWins = false;
	bool oWins = false;
	bool catWins = false;

	int newMove;

	do
	{
		do
		{
			cout << turn << "'s turn>"; 
			cin >> newMove;
		}
		while(	newMove < 1 || newMove > 9 || 
				((int)pow(2,newMove) & xMoves) == pow(2,newMove) || 
				((int)pow(2,newMove) & oMoves) == pow(2,newMove) );

		if( turn == 'X')
		{
			xMoves += (int)pow(2,newMove);
			turn = 'O';
		}
		else
		{
			oMoves += (int)pow(2,newMove);
			turn = 'X';
		}

		system("cls");

		for(int i = 1; i <= 9; i++)
		{
			if( (xMoves & (int)pow(2,i)) == (int)pow(2,i) )
			{
				cout << 'X';
			}
			else if( (oMoves & (int)pow(2,i)) == (int)pow(2,i) ) 
			{
				cout << 'O';			
			}
			else
			{
				cout << i;
			}

			if(i % 3 == 0)
			{
				cout << endl;
			}
		}
		cout << endl;

		if( (xMoves & 14 ) == 14 ||
			(xMoves & 112 ) ==  112 ||
			(xMoves & 896 ) == 896 ||
			(xMoves & 164 ) == 146 ||
			(xMoves & 292 ) == 292 ||
			(xMoves & 584 ) == 584 ||
			(xMoves & 546 ) == 546 ||
			(xMoves & 168 ) == 168 )
		{
			xWins = true;
			cout << "X wins" << endl;
		}

		if( (oMoves & 14 ) == 14 ||
			(oMoves & 112 ) ==  112 ||
			(oMoves & 896 ) == 896 ||
			(oMoves & 164 ) == 146 ||
			(oMoves & 292 ) == 292 ||
			(oMoves & 584 ) == 584 ||
			(oMoves & 546 ) == 546 ||
			(oMoves & 168 ) == 168 )
		{
			oWins = true;
			cout << "O wins" << endl;
		}

		if( oMoves + xMoves == 1022 )
		{
			catWins = true;
			cout << "Cat wins" << endl;
		}

	}
	while( !xWins && !oWins && !catWins );
}