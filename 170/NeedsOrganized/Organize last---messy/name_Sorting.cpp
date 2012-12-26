
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int MAX_NAMES = 20;

void DisplayNames(const string Names[], int NamesEntered)
{
	for(int i = 0; i < NamesEntered; i++)
	{
		cout << Names[i] << endl;
	}
}

void GetNames(string Names[], int& NamesEntered)
{
	bool EmptyNameEntered = false;
	do
	{
		getline(cin,Names[NamesEntered]);
		if (Names[NamesEntered] == "")
		{
			EmptyNameEntered = true;
		}
		else
		{
			NamesEntered++;
		}
	}
	while(NamesEntered < MAX_NAMES && !EmptyNameEntered );
}

void Swap(string& x, string& y)
{
	string Temp = x;
	x = y;
	y = Temp;
}

void AlphabetizeNames(string Names[], int NamesEntered)
{
	for(int k =0; k <= NamesEntered -2; k++)
	{
		int Smallest = k;

		for(int i = k+1; i <= NamesEntered-1; i++)
		{
			if (Names[i] < Names[Smallest])
			{
				Smallest = i;
			}
		}
		Swap(Names[Smallest],Names[k]);
	}

}

void ReverseNames(string Names[], int NamesEntered)
{
	for(int i = 0; i < NamesEntered; i++)
	{
		int IndexOfSpace = Names[i].find(' ');

		string NewString;
		NewString = Names[i].substr(IndexOfSpace + 1) + " " +
					Names[i].substr(0,IndexOfSpace);

		Names[i] = NewString;
	}
}


int main()
{
	string Names[MAX_NAMES];
	int NamesEntered = 0;

	GetNames(Names,NamesEntered);
	ReverseNames(Names,NamesEntered);
	AlphabetizeNames(Names,NamesEntered);
	ReverseNames(Names,NamesEntered);
	DisplayNames(Names,NamesEntered);
    
    cin.get();
    return 0;
}









