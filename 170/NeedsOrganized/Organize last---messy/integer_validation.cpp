#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int getInt( char prompt[], char errorMessage[] )
{
	int x = 0;
	bool done = false;

	do
	{
		cout << prompt;
		cin >> x;
		if(cin.fail())
		{
			done = false;
			cout << errorMessage;
			x = 0;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else
		{
			done = true;
		}
	}
	while(!done);

	return x;
}

void main()
{

	int x;
	x = getInt("Give me an int: ", "Those are letters not numbers...\n");
	cout << x << endl;


}
