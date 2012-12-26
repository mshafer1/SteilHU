#include <iostream>
using namespace std;

int power( int x, int y ); //function prototype

void displayStuff( int x, int y )
{
	cout << "Test" << x << endl;
}

int seven()
{
	//logic

	return 7;
}

void displayAbsoluteValue( int x )
{
	if( x < 0 )
	{
		cout << -1 * x << endl;
	}
	else
	{
		cout << x << endl;
	}
}

void main()
{
	displayStuff(8,3);
	cout << seven() << endl;
	displayAbsoluteValue( -99 );
	displayAbsoluteValue( -9 );
	displayAbsoluteValue( 8 );

	cout << power(power(3,power(9,2)),5);

}

int power( int x, int y )
{
	int result = 1;

	if( y > 0 )
	{
		while( y > 0 )
		{
			result = result * x;
			y--;
		}
	}

	return result;
}
