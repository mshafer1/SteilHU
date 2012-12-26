#include<iostream>

using namespace std;

void DisplayBoard(char Board[3][3])
{
	for(int row = 0; row < 3; row++)
	{
		for(int column = 0; column < 3; column++)
		{
			cout << Board[row][column] << " ";
		}
		cout << endl;
	}
}

bool MakeMove(char Board[3][3], char command, char Mark)	
{
	bool Worked = false;

	for(int row = 0; row < 3; row++)
	{
		for(int column = 0; column < 3; column++)
		{
			if (Board[row][column] == command)
			{
				Board[row][column] = Mark;
				Worked = true;
			}
		}
	}
	return Worked;
}

void SwitchMark(char& Mark)
{
	if(Mark == 'X')
	{
		Mark = 'O';
	}
	else
	{
		Mark = 'X';
	}
}

void main()
{
	char Board[3][3] = {'7','8','9','4','5','6','1','2','3'};

	char command;
	char Mark = 'X';

	DisplayBoard(Board);
	cout << Mark << "'s turn" << endl;

	cin >> command;

	while(command != 'q')
	{	
		if (MakeMove(Board, command, Mark))	
		{
			DisplayBoard(Board);

			SwitchMark(Mark);
			cout << Mark << "'s turn" << endl;
			
			cin >> command;
		}
		else
		{
			cout << "Try Again " << Mark << ": " ;
			cin >> command;
		}
	}
}