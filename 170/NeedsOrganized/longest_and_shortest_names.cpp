#include<iostream>
#include<string>

using namespace std;

void ShowNamesWithLenght(string Names[], int Length, int TotalNames);

void main()
{
	const int MAX_NAMES = 100;
	string Names[MAX_NAMES];

	int ShortestLength;
	int LongestLength;
	int TotalNames = 0;
	
	cout << "Enter names:" << endl;
	getline(cin,Names[TotalNames]);

	ShortestLength = Names[TotalNames].length();
	LongestLength = Names[TotalNames].length();

	while(Names[TotalNames] != "Quit" && TotalNames < MAX_NAMES)
	{
		TotalNames++;
		getline(cin,Names[TotalNames]);

		if (Names[TotalNames] != "Quit")
		{
			if (Names[TotalNames].length() < ShortestLength)
			{
				ShortestLength = Names[TotalNames].length();
			}
			if (Names[TotalNames].length() > LongestLength)
			{
				LongestLength = Names[TotalNames].length();
			}
		}
	}

	cout << "Longest Name(s):" << endl;
	ShowNamesWithLenght(Names, LongestLength, TotalNames);
	cout << "Shortest Name(s):" << endl;
	ShowNamesWithLenght(Names, ShortestLength, TotalNames);

}

void ShowNamesWithLenght(string Names[], int Length, int TotalNames)
{
	for (int i = 0; i < TotalNames; i++)
	{
		if (Names[i].length() == Length)
		{
			cout << Names[i] << endl;
		}
	}
}
