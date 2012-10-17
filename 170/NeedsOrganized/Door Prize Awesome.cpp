#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

const int MAX_NAMES = 100;
const int MAX_NAME_LENGTH = 50;

void displayNames(char names[][MAX_NAME_LENGTH], int namesEntered)
{
	for(int i = 0; i < namesEntered; i++)
	{
		cout << names[i] << endl;
	}
}

void writeNamesToFile(char names[][MAX_NAME_LENGTH], int namesEntered)
{
	ofstream fout;
	fout.open("output.txt", ios::app);

	for(int i = 0; i < namesEntered; i++)
	{
		fout << names[i] << endl;
	}

	fout.close();
}


void sortNames(char names[][MAX_NAME_LENGTH], int namesEntered)
{
	char Temp[MAX_NAME_LENGTH];

	for (int Passes = 0; Passes < namesEntered - 1; Passes++)
	{
		for (int Comparisons = 0; Comparisons < namesEntered - Passes - 1; Comparisons++)
		{
			if (_stricmp(names[Comparisons], names[Comparisons + 1]) > 0)
			{
				strcpy_s(Temp, names[Comparisons]);
				strcpy_s(names[Comparisons],names[Comparisons + 1]);
				strcpy_s(names[Comparisons + 1], Temp);
			}
		}
	}
}


bool nameIsInList(char newName[], char names[][MAX_NAME_LENGTH], int namesEntered)
{
	bool result = false;
	
	for(int i = 0; i < namesEntered; i++)
	{
		if(_stricmp(newName, names[i]) == 0)
		{
			result = true;
		}
	}

	return result;
}

void main()
{
	srand((unsigned int) time(NULL));
	char names[MAX_NAMES][MAX_NAME_LENGTH];
	char newName[MAX_NAME_LENGTH];
	int namesEntered = 0;

	do
	{
		cin.getline(newName, MAX_NAME_LENGTH);

		if( !nameIsInList(newName,names, namesEntered) && 
			_stricmp(newName, "Quit") != 0 )
		{
			strcpy_s(names[namesEntered], newName);
			namesEntered++;
		}

	}
	while(_stricmp(newName, "Quit") != 0);

	sortNames(names, namesEntered);
	displayNames(names, namesEntered);
	writeNamesToFile(names, namesEntered);

	if(namesEntered > 0)
	{
		int indexOfWinner = rand() % namesEntered;
		cout << "out of " << namesEntered << " students ";
		cout << names[indexOfWinner] << " wins a new car" << endl;
	}

}




