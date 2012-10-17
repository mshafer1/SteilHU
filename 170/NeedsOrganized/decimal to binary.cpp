// Program: DecimalToBinary.cpp
// Author:	Dana Steil
// Date:    January 29, 2001

#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	int Decimal;
	int Power;
	char UserCommand = 'y';

	while (UserCommand == 'y')
	{
		cout << "Enter a positive decimal integer to convert to binary: ";
		cin >> Decimal;

		cout << "The dinary value is ";

		Power = 0;

		while (pow(2,Power) <= Decimal)
		{
			Power = Power + 1;
		}

		while ( Power >= 0 )
		{
			if (Decimal >= pow(2,Power))
			{
				cout << "1";
				Decimal = Decimal - pow(2,Power);
			}
			else
			{
				cout << "0";
			}

			Power = Power - 1;
		}
		
		cout << endl << endl << "Would you like to convert another decimal number(y/n)? ";
		cin >> UserCommand;
	}
}