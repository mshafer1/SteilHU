//this program receives a number from the user and
//  changes it to represent a dollar amount. This
//  practices altering how floats are displayed to
//  the console by changing cout

#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

void displayAsMoney(float money) //copy of the variable in main()
{
	money += 0.0005; //fix the rounding error in case of 0.x45
	
	int originalPrecision = cout.precision();
        //store the current state of cout.precision()
        
	int originalFlags = cout.flags();
        //store the current state of cout.flags()
        
	cout.precision(2);
	    //change cout to display up to 2 significant figures
	    
	cout.setf(ios_base::fixed);
	    //change cout to display no fewer places than cout.precision()
	    //in other words, 1 will now be displayed as 1.00
	    
	cout << "display with altered cout: $" << money << endl;
    
    
//now that the function has served its purpose, we
// can return cout to the state received. In essence, 
// main() doesn't know it was ever changed in the 
// first place.

	cout.precision( originalPrecision );
	if( originalFlags != cout.flags() )
	{   
		cout.unsetf(ios_base::fixed);
	}
}

int main()
{
	cout << "Enter an amount to fix: ";
	float money;
	cin >> money;
	cin.ignore();
	
	cout << "display with original cout: $" << money << endl;
	
	displayAsMoney(money);
	
	cout << "display with cout restored to original: $" << money;
 
    cin.get();
    return 0;
}
