//this program seeds the random number generator and displays 100 random numbers.

#include<iostream>
#include<cstdlib> 	// contains rand and srand.
#include<time.h> 	// contains time.
						//time is a good way to seed the random number generator
						// because time always changes.
using std::cout;
using std::endl;
using std::cin;

int main()
{
	srand(time(0)); //Seeding the random number generator.
					//Remember, you should never need to seed more than once.

	for(int i = 0; i < 100; i++)
	{
		cout << i + 1 << ": " << rand() << endl;
	}
	
	cin.get();
	return 0;
}

