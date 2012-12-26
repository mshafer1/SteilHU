//this program introduces the enumerator, the intrinsic data type "enum"

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

enum eMonths
{
	JANUARY = 1, 
	FEBUARY,    // this equals 2
	MARCH,      // this equals 3    
	APRIL,      // etc...
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER 
};

eMonths& operator++(eMonths& Month, int Garbage)
{ 	//overloading the ++ operator
	if (Month != DECEMBER)
	{
		Month = (eMonths)( Month + 1 );
	}
	else
	{
		Month = JANUARY;
	}
	return Month;
}

int main()
{
	eMonths Month = JANUARY;
	cout << "Year? ";
	int year;
	cin >> year;
	cin.ignore();

	char userInput = 'y';
	while(userInput == 'y')
	{
		
		do
		{
			cout << (int)Month << '/' << year << endl;
			Month++;
		}while(Month != JANUARY);
		
		year++;
		cout << endl << "See next year? (y/n)"; 
		cin >> userInput;
		cin.ignore();
	}
	
    cin.get();
    return 0;
}
