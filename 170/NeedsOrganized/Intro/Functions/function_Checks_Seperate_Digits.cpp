//this rough program seperates digits, 
//as you would do in a check-writing program

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
 
int hundredsPlace( int money );
int tensPlace( int money );
int onesPlace( int money );
int teensPlace( int money );
void displayMoneyTrio( int trio, string category );

int main()
{
	int wholeMoney;
	cout << "Whole Number?\n>";
	cin >> wholeMoney;

	int billions = wholeMoney / 1000000000;
	wholeMoney = wholeMoney - billions * 1000000000;

	int millions = wholeMoney / 1000000;
	wholeMoney = wholeMoney - millions * 1000000;

	int thousands = wholeMoney / 1000;
	wholeMoney = wholeMoney - thousands * 1000;

	int smallGroup = wholeMoney;


	displayMoneyTrio( billions, "\nbillions place:" );
	displayMoneyTrio( millions, "\nmillions place:" );
	displayMoneyTrio( thousands, "\nthousands place:" );
	displayMoneyTrio( smallGroup, "\nEverything else:" );
	
	cin.get(); cin.get();
	return 0;

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
		cout << category << endl;
		cout << "There are " << hundredsPlace( trio ) << " hundreds\n";
		cout << "There are " << tensPlace( trio ) << " tens\n";
		if(teensPlace( trio ))
		{
			cout << "   - 'Teen' number: " << teensPlace( trio ) << endl;
		}
		cout << "There are " << onesPlace( trio ) << " ones\n";
	}
}