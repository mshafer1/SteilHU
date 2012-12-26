
#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void main()
{
	char goalPhrase[100];
	char progressPhrase[100];
	int charactersInPhrase = -1;

	do
	{
		charactersInPhrase++;
		goalPhrase[charactersInPhrase] = toupper(getch());
		if(goalPhrase[charactersInPhrase] != '\r')
		{
			if(goalPhrase[charactersInPhrase] == ' ')
			{
				cout <<  ' ';
			}
			else if(goalPhrase[charactersInPhrase] == '\b')
			{
				charactersInPhrase = charactersInPhrase - 2;
			}
			else
			{
				cout << "-";
			}
		}
	}
	while(goalPhrase[charactersInPhrase] != '\r');

	for(int i = 0; i < charactersInPhrase; i++)
	{
		progressPhrase[i] = '-';
		if(goalPhrase[i] == ' ')
		{
			progressPhrase[i] = ' ';
		}
	}

	//display hangman
	cout << "I am a hangman\n";

	//dipaly progressPhrase
	for(int i = 0; i < charactersInPhrase; i++)
	{
		cout << progressPhrase[i];
	}
	cout << endl;

	//get a guess

	//see if the guess is in the goalPhrase
	//if it is, change the right letters in the progressPhrase 
	//if it is not, add 1 to the number of missed guesses
	//go back to top of loop


	
}