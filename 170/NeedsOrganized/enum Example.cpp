#include<iostream>
using namespace std;

enum eMonths
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
	DECEMBER
};

eMonths& operator++(eMonths& Month, int Garbage)
{
	if (Month != DECEMBER)
	{
		Month = static_cast<eMonths>( Month + 1 );
	}
	else
	{
		Month = JANUARY;
	}
	return Month;
}

void main()
{
	eMonths Month = JANUARY;

	do
	{
		cout << "Current Month number is"  << Month << endl;

		Month++;
	}while(Month != JANUARY);


}