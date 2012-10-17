// Dana Steil 
// Fall 2000
// Logical Operators example

#include <iostream>
using namespace std;

void main()
{
	//Simple equality comparison
	if ( 1 == 1 )
	{
		cout << "Yes, 1 equals 1"  << endl;
	}

	if ( 1 == 2 )
	{
		cout << "Yes, 1 equals 2"  << endl;
	}

	//Not distributed over simple equality
	if (!( 1 == 1 ))
	{
		cout << "Yes, 1 does not equal 1"  << endl;
	}

	if (!( 1 == 2 ))
	{
		cout << "Yes, 1 does not equal 2"  << endl;
	}

	// And equality comparison
	if (1 == 1 && 2 == 2)
	{
		cout << "Yes, 1 equals 1 and 2 equals 2"  << endl;
	}

	if (1 == 1 && 2 == 3)
	{
		cout << "Yes, 1 equals 1 and 2 equals 3"  << endl;
	}

	// Or equality comparison
	if (1 == 1 || 2 == 2)
	{
		cout << "Yes, 1 equals 1 or 2 equals 2"  << endl;
	}

	if (1 == 1 || 2 == 3)
	{
		cout << "Yes, 1 equals 1 or 2 equals 3"  << endl;
	}

	//Not distributed over And
	if (!(1 == 1 && 2 == 3))				// (1 != 1 || 2 != 3)
	{
		cout << "Yes, 1 does not equal 1 or 2 does not equal 3"  << endl;
	}

	//Not distributed over Or
	if (!(1 == 1 || 2 == 3))				// (1 != 1 && 2 != 3)
	{
		cout << "Yes, 1 does not equal 1 and 2 does not equal 3"  << endl;
	}

	//Or - And equality comparitson
	if (1 == 2 || (2 == 2 && 3 == 3))
	{
		cout << "Yes, 1 equals 2 or (2 equals 2 and 3 equals 3)"  << endl;
	}

	//Not distributed over Or - And equality comparitson
	if (!(1 == 2 || (2 == 2 && 3 == 3)))	// (1 != 2 && (2 !=2 || 3 != 3))
	{
		cout << "Yes, 1 does not equal 2 and (2 does not equal 2 or 3 does not equal 3)"  << endl;
	}


	int x = 8;

	x >> 1;

	cout << x;

	// Example of the bitwise right shift operator
	int nNumA=8;    // beginning value is 8

	cout << nNumA >> 2;     // ending value is 2

	cout << nNumA;



}

