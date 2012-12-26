#include<iostream>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;

void PrintForDenomination(double& TotalChange, double Denomination);
void MakeChange(double PurchasePrice, double AmountPaid);

enum x 
{
	z = .98;
}

void main()
{
	double PurchasePrice;
	double AmountPaid;

	cout << "Please enter the purchase price > ";
	cin >> PurchasePrice;

	cout << "PleaseEnter the amount paid > ";
	cin >> AmountPaid;

	MakeChange(PurchasePrice, AmountPaid);
}

void MakeChange(double PurchasePrice, double AmountPaid)
{
	double TotalChange = AmountPaid - PurchasePrice;

	PrintForDenomination(TotalChange, 100);
	PrintForDenomination(TotalChange, 50);
	PrintForDenomination(TotalChange, 20);
	PrintForDenomination(TotalChange, 10);
	PrintForDenomination(TotalChange, 5);
	PrintForDenomination(TotalChange, 1);
	PrintForDenomination(TotalChange, .25);
	PrintForDenomination(TotalChange, .1);
	PrintForDenomination(TotalChange, .05);
	PrintForDenomination(TotalChange, .01);
}

void PrintForDenomination(double& TotalChange, double Denomination)
{
	int UnitsOfCurrentDenomination = (int) (TotalChange/Denomination);

	TotalChange = TotalChange - ( Denomination * UnitsOfCurrentDenomination );

	if (UnitsOfCurrentDenomination > 0)
	{
		if ( Denomination >= 1 )
		{
			cout << UnitsOfCurrentDenomination << " $" << Denomination << " bill";
		}
		else
		{
			if ( Denomination == .25 )
			{
				cout << UnitsOfCurrentDenomination << " quarter";
			}
			else if (Denomination == .10 )
			{
				cout << UnitsOfCurrentDenomination << " dime";
			}
			else if (Denomination == .05 )
			{
				cout << UnitsOfCurrentDenomination << " nickel";
			}
			else if (Denomination == .01 )
			{
				cout << UnitsOfCurrentDenomination << " penny";
			}
		}

		if ( UnitsOfCurrentDenomination > 1 )
		{
			cout << 's';
		}

		cout << endl;
 
