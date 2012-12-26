#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;
//				84
// 1|2|4		7
//------
//8|16|32		56
//------
//64|128|256	448

//73  146  292   273

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

void main()
{


	int xMoves = 0; //00000011
	int oMoves = 0;	//00000100

	bool xTurn = true;
	int move;
	bool continueGame = true; 

	while(continueGame)
	{
		system("cls");

		if((xMoves & 7) == 7 || 
			(xMoves & 56) == 56 || 
			(xMoves & 448) == 448 || 
			(xMoves & 73) == 73 ||
			(xMoves & 146) == 146 ||
			(xMoves & 292) == 292 ||
			(xMoves & 273) == 273 ||
			(xMoves & 84) == 84)
		{
			showFlashingText("x wins");
			continueGame = false;
		}
		else if((oMoves & 7) == 7 || 
			(oMoves & 56) == 56 || 
			(oMoves & 448) == 448 || 
			(oMoves & 73) == 73 ||
			(oMoves & 146) == 146 ||
			(oMoves & 292) == 292 ||
			(oMoves & 273) == 273 ||
			(oMoves & 84) == 84)
		{
			showFlashingText("o wins");
			continueGame = false;
		}
		else if(xMoves + oMoves == 511)
		{
			cout << "Cat wins ";
			continueGame = false;
		}

		//display board
		for(int i = 0; i <= 8; i++)
		{
			if((xMoves & (int)pow(2.0,i)) == (int)pow(2.0,i) )
			{
				cout << "X";
			}
			else if((oMoves & (int)pow(2.0,i)) == (int)pow(2.0,i) )
			{
				cout << "O";
			}
			else
			{
				if( continueGame)
				{
					cout << i + 1;
				}
				else
				{
					cout << " ";
				}
			}

			if(i == 2 || i == 5 )
			{
				cout << endl << "-----"  << endl;
			}
			else if( i != 8 )
			{
				cout << "|";
			}
		}

		if( continueGame)
		{
			if(xTurn)
			{
				cout << "\nX's turn\n";
			}
			else
			{
				cout << "\nO's turn\n";
			}


			int moveResult;
			do
			{
				cout << "Enter move(1-9): " ;
				cin >> move;
				move--;
				moveResult = (int)pow(2.0,move);

			}
			while(	move < 0 ||
					move > 8 ||
					(xMoves & moveResult) == moveResult ||
					(oMoves & moveResult) == moveResult);

			if(xTurn)
			{
				xMoves = xMoves + (int)pow(2.0,move);
				//xMoves = (xMoves | (int)pow(2.0,move));
				xTurn = false;
			}
			else
			{
				oMoves = oMoves + (int)pow(2.0,move);
				xTurn = true;
			}
		}

	}

	
}