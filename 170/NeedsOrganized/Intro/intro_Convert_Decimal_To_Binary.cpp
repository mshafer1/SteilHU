// this program converts decimal (base 10) numbers to binary (base 2) numbers

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int decimal;
	int power;
	char userCommand = 'y';

	while (userCommand == 'y' || userCommand == 'Y')
	{
		cout << "\nEnter a positive decimal integer to convert to binary: ";
		cin >> decimal;
		cin.ignore(); //drop the carriage return from the buffer

		cout << "The binary value is ";

		power = 0;
		while (pow(2,power) <= decimal)//pow is in the math.h library
		{
			power = power + 1;
		}

		while ( power >= 0 )
		{
			if (decimal >= pow(2,power))
			{
				cout << "1";
				decimal = decimal - pow(2,power);
			}
			else
			{
				cout << "0";
			}

			power = power - 1;
		}
		
		cout << endl << endl << "Would you like to convert another decimal number(y/n)? ";
		cin >> userCommand;
		cin.ignore();
	}
	return 0;
}
