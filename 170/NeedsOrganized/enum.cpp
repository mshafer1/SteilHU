#include<iostream.h>

void main()
{
	enum MONTHS
	{
		JANUARY = 1, 
		FEBUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER,
	}; 

	int Month;

	cout << "Please enter a month between 1-12 (0 to stop)";
	cin >> Month;

	while(Month != 0)
	{
		if (Month == APRIL || Month == JUNE ||
			 Month == SEPTEMBER || Month == NOVEMBER)
		{
			cout << "Month " << Month << " has 30 days." << endl;
		}
		else if (Month == JANUARY || Month == MARCH || 
					Month == MAY || Month == JULY ||
					Month == AUGUST || Month  == OCTOBER || Month == DECEMBER)
		{
			cout << "Month " << Month << " has 31 days." << endl;
		}
		else if(Month == FEBUARY)
		{
			cout << "Month " << Month << " has 29 days, 28 in a leap year" << endl;
		}
		else
		{
			cout << Month << " is not a valid month." << endl;
		}
		
		cout << "Please enter a month between 1-12 (0 to stop)";
		cin >> Month;
	}

}