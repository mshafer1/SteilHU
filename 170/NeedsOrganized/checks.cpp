#include <iostream>
#include <string>
using namespace std;
 
int hundredsPlace( int money );
int tensPlace( int money );
int onesPlace( int money );
int teensPlace( int money );
void displayMoneyTrio( int trio, string category );

void main()
{
	int wholeMoney;
	cin >> wholeMoney;

	int billions = wholeMoney / 1000000000;
	wholeMoney = wholeMoney - billions * 1000000000;

	int millions = wholeMoney / 1000000;
	wholeMoney = wholeMoney - millions * 1000000;

	int thousands = wholeMoney / 1000;
	wholeMoney = wholeMoney - thousands * 1000;

	int smallGroup = wholeMoney;


	displayMoneyTrio( billions, "billion" );
	displayMoneyTrio( millions, "million" );
	displayMoneyTrio( thousands, "thousand" );
	displayMoneyTrio( smallGroup, "" );

}

int hundredsPlace( int money )
{
	return money / 100;
}

int tensPlace( int money )
{
	int hundreds = hundredsPlace(money) * 100;
	return (money - hundreds) / 10;
}

int onesPlace( int money )
{
	int hundreds = hundredsPlace(money) * 100;
	int tens = tensPlace( money ) * 10;
	return money - hundreds - tens;
}

int teensPlace( int money )
{
	int result = 0;

	if( tensPlace( money ) == 1 )
	{
		int hundreds = hundredsPlace(money) * 100;
		result = money - hundreds;
	}

	return result;
}

void displayMoneyTrio( int trio, string category )
{
	if( trio  > 0 )
	{
		cout << "There are " << displayDigit(hundredsPlace( trio ) ) << " hundreds\n";
		cout << "There are " << tensPlace( trio ) << " tens\n";
		cout << "There are " << teensPlace( trio ) << " teens\n";
		cout << "There are " << onesPlace( trio ) << " ones\n";
		cout << category << endl;
	}
}