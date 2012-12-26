//this program introduces the logical operators

/*
    ==  "Equal to"
    >   "Greater than"
    >=  "Greater than or equal to"
    <   "Less than"
    <=  "Less than or equal to"
    !   "Not"
    !=  "Not equal to"
    &&  "And"
    ||  "Or"
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
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
	
	

	//"Not" distributed over simple equality
	if (!( 1 == 1 ))
	{
		cout << "Yes, 1 does not equal 1"  << endl;
	}

	if (!( 1 == 2 ))
	{
		cout << "Yes, 1 does not equal 2"  << endl;
	}
	
	

	// "And" equality comparison
	if (1 == 1 && 2 == 2)
	//    1st       2nd
	{
		cout << "Yes, 1 equals 1 and 2 equals 2"  << endl;
	}

	if (1 == 1 && 2 == 3)
	{
		cout << "Yes, 1 equals 1 and 2 equals 3"  << endl;
	}
	
	

	// "Or" equality comparison
	if (1 == 1 || 2 == 2)
	{   //if 1 == 1, then the next condition (2 == 2) is not tested
		cout << "Yes, 1 equals 1 or 2 equals 2"  << endl;
	}

	if (1 == 1 || 2 == 3)
	{
		cout << "Yes, 1 equals 1 or 2 equals 3"  << endl;
	}
	
	

	//"Not", distributed over "And"
	if (!(1 == 1 && 2 == 3))  
	{   // same as "if(1 != 1 || 2 != 3)"
		cout << "Yes, 1 does not equal 1 or 2 does not equal 3"  << endl;
	}

	//"Not", distributed over "Or"
	if (!(1 == 1 || 2 == 3))				
	{   // same as "if (1 != 1 && 2 != 3)"
		cout << "Yes, 1 does not equal 1 and 2 does not equal 3"  << endl;
	}

	//"Or"/"And" equality comparison
	if (1 == 2 || (2 == 2 && 3 == 3))
	{
		cout << "Yes, 1 equals 2 or (2 equals 2 and 3 equals 3)"  << endl;
	}

	//"Not", distributed over "Or"/"And" equality comparison
	if (!(1 == 2 || (2 == 2 && 3 == 3)))	// (1 != 2 && (2 !=2 || 3 != 3))
	{
		cout << "Yes, 1 does not equal 2 and (2 does not equal 2 or 3 does not equal 3)"  << endl;
	}
    cin.get();
    return 0;
}

