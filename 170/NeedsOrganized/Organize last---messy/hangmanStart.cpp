#include <iostream>
#include <conio.h>

using namespace std;

const int MAX_WORD_LENGTH = 101;

int stringLength(char word[])
{
	int result =0;

	while(word[result] != '\0')
	{
		result++;
	}

	return result;
}

void updateProgress(char progress[], char word[], int length, char guess)
{
	for(int i = 0; i < length; i++)
	{
		if(word[i] == guess)
		{
			progress[i] = guess;
		}
	}
}

void initializeProgress(char progress[], char word[], int length)
{
	for(int i = 0; i < length; i++)
	{
		if(word[i] == ' ')
		{
			progress[i] = ' ';
		}
		else
		{
			progress[i] = '-';
		}
	}
	progress[length] = '\0';

}

void getSecretWord(char word[])
{
	char c;
	int i = 0;
	do
	{
		c = _getch();
		
		switch(c)
		{
			case '\b':
				cout << "\b \b";
				i--;
				break;
			case '\r':
				break;
			case ' ':
				cout << ' ';
				word[i] = c;
				i++;
				break;
			default:
				cout << "*";
				i++;
				word[i] = c;
				break;
		}
	}
	while(c != '\r');

	word[i] = '\0';
}




void main()
{
	char word[MAX_WORD_LENGTH];
	char progress[MAX_WORD_LENGTH];

	//prompt	
	getSecretWord(word);
	initializeProgress(progress, word, stringLength(word));

	cout << progress << endl;
}

