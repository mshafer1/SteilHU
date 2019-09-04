//#include <iomanip>
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;


void main()
{
	const int MONTH_COLUMN_WIDTH = 6;
	const int FINANCE_CHARGE_COLUMN_WIDTH = 10;
	const int BALANCE_COLUMN_WIDTH = 12;

	float InitialBalance = 0;
	float Balance = 0;
	float Rate = 1;
	float InterestChargedThisMonth = 0;
	float MonthyServiceCharge = 0;
	float Payment = 0;
	int Month = 1;

	cout <<endl<<"Initial balance: ";
	cin >> InitialBalance;

	cout <<"Interest rate: ";
	cin >> Rate;
	
	cout <<"Monthly Service Charge: ";
	cin >> MonthyServiceCharge;
	
	cout <<"Monthly payment: ";
	cin >> Payment;

	InterestChargedThisMonth = InitialBalance * (Rate / 100);

	Balance = (InterestChargedThisMonth + InitialBalance + MonthyServiceCharge) - Payment;

	cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

	if (Balance >= InitialBalance)
	{
		cout << endl;
		cout << "It is not possible to pay off your credit card " << endl;
		cout << "given your current monthly payment.  " << endl;
		
		cout << "You must pay more than ";
		cout << InterestChargedThisMonth + MonthyServiceCharge << endl;
	}
	else
	{
		cout << endl << endl;
		cout << setw(MONTH_COLUMN_WIDTH) << "Month";
		cout << setw(FINANCE_CHARGE_COLUMN_WIDTH) << "F/C";
		cout << setw(BALANCE_COLUMN_WIDTH) << "Balance";
		cout << endl;

		while (Balance > 0)
		{
			cout << setw(MONTH_COLUMN_WIDTH) << Month;
			cout << setw(FINANCE_CHARGE_COLUMN_WIDTH) << InterestChargedThisMonth;
			cout << setw(BALANCE_COLUMN_WIDTH) << Balance;
			cout << endl;

			Month++;
			
			InterestChargedThisMonth = Balance * (Rate / 100);
			Balance = (InterestChargedThisMonth + Balance + MonthyServiceCharge) - Payment;
		}

		cout << "You paid a total of "<< Month * Payment << " dollars ";
		cout << "for a " << InitialBalance << " dollar loan." << endl;
	}
}
