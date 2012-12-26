#include<iostream>
using namespace std;
 
 
void displayMoneyAsText( double money );
void displayHundredsAsText( int money);

void main()
{
      double money;
 
      do
      {
            cout << "Amount? ";
            cin >> money;
 
            if( money > 0 )
            {
                  displayMoneyAsText( money);
            }
      }
      while( money > 0 );
 
}
 
void displayMoneyAsText( double money )
{
	money = money + .005;
	int wholeMoney = money;
	int cents = (money - wholeMoney) * 100;
	int billions = wholeMoney/1000000000;
	wholeMoney -= (billions * 1000000000);
	int millions = wholeMoney/1000000;
	wholeMoney -= (millions * 1000000);
	int thousands = wholeMoney/1000;
	wholeMoney -= (thousands * 1000);
	int hundreds = wholeMoney;

	if(billions > 0)
	{
		displayHundredsAsText(billions);
		cout << "Billion ";
	}
	if(millions > 0)
	{
		displayHundredsAsText(millions);
		cout << "Million ";
	}
	if(thousands > 0)
	{
		displayHundredsAsText(thousands);
		cout << "Thousand ";
	}

	displayHundredsAsText(hundreds);
	cout << " Dollars"; // if there was only 1 dollar this should say dollar

}
 

void displayHundredsAsText( int money)
{
	//we know that money is 0-999

}