#include<iostream>
#include<iomanip>
#include<string>
#include<conio.h>

using namespace std;

void main()
{
	string s;
	string progress = "";
	char guess;

	cout << "Enter secret word>";
	getline(cin,s);


	for(int i = 0; i < s.length();i++)
	{
		progress += "-";
	}
	int badGuessCount = 0;

	while(progress != s)
	{
		cout << "guess? ";
		guess = getch();

		bool goodGuess = false;
		for(int i = 0; i < s.length();i++)
		{
			if(s[i] == guess)
			{
				goodGuess = true;
				progress[i] = guess;
			}
		}		

		if(!goodGuess)
		{
			badGuessCount++;
		}

		cout << progress << endl;
		cout << badGuessCount << endl;

	}

}