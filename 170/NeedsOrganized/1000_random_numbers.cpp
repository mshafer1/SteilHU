//this program seeds the random number generator and displays 100 random numbers.

#include<iostream>
#include<cstdlib> 	// contains rand and srand.
#include<time.h> 	// contains time.
						//time is a good way to seed the random number generator
						// because time is always changes.
using std::cout;
using std::endl;
using std::srand;
using std::rand;

int main()
{
	srand(time(0)); //Seeding the random number generator.
					//Remember, you should never need to seed more than once.

	for(int i = 0; i < 100; i++)
	{
		cout << rand() << endl;
	}
	
	return 0;
}

