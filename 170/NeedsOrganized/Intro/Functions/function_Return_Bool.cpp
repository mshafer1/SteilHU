//this program uses a function that returns a boolean

#include<iostream>

using std::cin;
using std::cout;

bool userWantsToContinue()
{
	bool Continue = false;
	char userCommand;

	cout << "Do you want to repeat? (y/n) ";
	cin >> userCommand;

	if (userCommand == 'y' || userCommand == 'Y')
	{
		Continue = true;
	}

	return Continue;
}

int main()
{
	do
	{
		//operations
	}
	while(userWantsToContinue());
	return 0;
}


		
