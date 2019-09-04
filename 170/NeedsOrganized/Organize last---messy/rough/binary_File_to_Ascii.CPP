//rough

#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>

using namespace std;

void ReadFile();

void main()
{
	ReadFile();
}

int ASCII(const char* Byte)
{
	int Result = 0;

	for(int i = 0; i < 8; i++)
	{
		if(Byte[i] == '1')
		{
			Result = Result + pow(2,7-i);
		}
	}

	return Result;
}

void ReadFile()
{
	ifstream fin;

	const int BYTE_LENGTH = 8;	
	char Byte[BYTE_LENGTH + 1];

	fin.open( "Name.txt" );

	if (!fin.fail())
	{
		while (! fin.eof())
		{
			fin >> Byte;
			cout << char(ASCII(Byte));
		}
	}
	else
	{
		cout << "Unable to open name.txt" << endl;
	}
	cout << endl;
	fin.close();
}