//this program receives a date from the user 
//    and checks to see if it is a valid date.

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int day;
	int month;
	int year = 0;
	int daysInMonth = 0;

	cout << "Year: ";
	cin >> year;
	cin.ignore();
	
	cout << "Month: ";
	cin >> month;
	cin.ignore();
	
	cout << "Day: ";
	cin >> day;
	cin.ignore();


	if(month == 9 || month == 4 || month == 6  || month == 11)
	{
		daysInMonth = 30;
	}
	else if(month == 2)
	{ //check for leap year
		if( year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			daysInMonth = 29;
		}
		else
		{
			daysInMonth = 28;
		}
	}
	else
	{
		daysInMonth = 31;
	}

	if( month >= 1 && month <= 12 && day > 0 && day <= daysInMonth)
	{
		cout << "\nValid date. \n\nPress any key to exit.\n" << endl;
	}
	else
	{
		cout << "\nInvalid date. \n\nPress any key to exit.\n" << endl;
	}

    cin.get();
    return 0;
}
