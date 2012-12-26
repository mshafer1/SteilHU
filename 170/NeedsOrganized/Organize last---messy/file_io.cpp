#include<iostream>
#include<fstream>

#include<string.h>

using namespace std;

void ReadFileOneCharacterAtATime();
void ReadFileOneLineAtATime();
void ReadFileIfItAlreadyExists();

void WriteFileOneCharacterAtATime();
void WriteFileOneLineAtATime();
void WriteFileIfItAlreadyExists();
void WriteFileIfItDoesNotExists();

void main()
{
	ReadFileOneCharacterAtATime();
	//ReadFileOneLineAtATime();
	//ReadFileIfItAlreadyExists();

	//WriteFileOneCharacterAtATime();
	//WriteFileOneLineAtATime();
	//WriteFileIfItAlreadyExists();
	//WriteFileIfItDoesNotExists();
}


void ReadFileOneCharacterAtATime()
{
	ifstream fin;

	char c;
	char FileName[50];

	cout << "File Name? ";
	cin >> FileName;

	fin.open( FileName );

	while (! fin.eof())
	{
		fin.get(c);

		if(! fin.eof())
		{
			cout << c;
		}
	}

	fin.close();
}

void ReadFileOneLineAtATime()
{
	ifstream fin;

	const int MAX_LINE_LENGTH = 200;
	const int MAX_FILE_NAME_LENGTH = 50;
	
	char Line[MAX_LINE_LENGTH];
	char FileName[MAX_FILE_NAME_LENGTH];

	cout << "File Name? ";
	cin >> FileName;

	fin.open( FileName );

	while (! fin.eof())
	{
		fin.getline(Line, MAX_LINE_LENGTH);
		cout << Line << endl;
	}

	fin.close();
}

void ReadFileIfItAlreadyExists()
{
	ifstream fin;

	const int MAX_LINE_LENGTH = 200;
	const int MAX_FILE_NAME_LENGTH = 50;
	
	char Line[MAX_LINE_LENGTH];
	char FileName[MAX_FILE_NAME_LENGTH];

	cout << "File Name? ";
	cin >> FileName;

	fin.open( FileName );

	if ( !fin.fail() )
	{
		while (! fin.eof())
		{
			fin.getline(Line, MAX_LINE_LENGTH);
			cout << Line << endl;
		}
	}

	fin.close();
}

void WriteFileOneCharacterAtATime()
{
	ofstream fout;

	char FileName[50];
	char StuffToWrite[] = "This is the data to write to the file";

	cout << "File Name? ";
	cin >> FileName;

	fout.open( FileName );

	int CharacterToWrite = (int) strlen(StuffToWrite);

	for ( int i = 0; i < CharacterToWrite; i++ )
	{
		fout.put(StuffToWrite[i]);
	}

	fout.close();
}

void WriteFileOneLineAtATime()
{
	ofstream fout;

	char FileName[50];
	char StuffToWrite[] = "This is the data to write to the file";

	cout << "File Name? ";
	cin >> FileName;

	fout.open( FileName );

	fout << StuffToWrite;

	fout.close();
}

void WriteFileIfItAlreadyExists()
{
	ofstream fout;

	char FileName[50];
	char StuffToWrite[] = "This is the data to write to the file";

	cout << "File Name? ";
	cin >> FileName;

	fout.open( FileName, ios::in | ios::out );

	if(!fout.fail())
	{
		cout << "Writing" << endl;
		fout << StuffToWrite;
	}
	else
	{
		cout << "File not found; write failed" << endl;
	}

	fout.close();
}

void WriteFileIfItDoesNotExists()
{
	ofstream fout;
	ifstream fin;

	char FileName[50];
	char StuffToWrite[] = "This is the data to write to the file";

	cout << "File Name? ";
	cin >> FileName;

	fin.open(FileName);
	fin.close();
	
	//if the file could not be open for input it did not exist
	if(fin.fail())
	{
		fout.open( FileName);

		if(!fout.fail())
		{
			cout << "Writing" << endl;
			fout << StuffToWrite;
		}
	
		fout.close();
	}
	else
	{
		cout << "File already exists; write failed" << endl;
	}

}

