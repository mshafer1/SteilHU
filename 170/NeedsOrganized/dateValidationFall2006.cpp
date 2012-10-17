#include<iostream>

using namespace std;

void main()
{
	int day;
	int month;
	int year = 0;
	int daysInMonth = 0;

	cout << "Year Month Day ";
	cin >> year;
	cin >> month;
	cin >> day;


	if(month == 9 || month == 4 || month == 6  || month == 11)
	{
		daysInMonth = 30;
	}
	else if(month == 2)
	{
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
		cout << "valid date" << endl;
	}
	else
	{
		cout << "invalid date" << endl;
	}


}
