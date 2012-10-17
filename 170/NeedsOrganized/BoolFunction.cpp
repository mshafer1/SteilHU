#include<iostream>
#include<iomanip>

using namespace std;

bool UserWantsToContinue()
{
	bool Continue = false;
	char UserCommand;

	cout << "Do you want to ___ again?";
	cin >> UserCommand;

	if (UserCommand == 'y' || UserCommand == 'Y')
	{
		Continue = true;
	}

	return Continue;
}

void main()
{
	do
	{
		//do what the program is designed to do
	}
	while(UserWantsToContinue());
}


		
