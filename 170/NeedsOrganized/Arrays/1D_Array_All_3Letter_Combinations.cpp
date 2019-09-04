//this program outputs to the console every possible combination of 3 lowercase letters.
#include <iostream>

int main()
{
	char guess[] = "aaa";

	while(guess[0] <= 'z')
	{
		guess[1] = 'a';
		while(guess[1] <= 'z')
		{
			guess[2] = 'a';
			while(guess[2] <= 'z')
			{
				std::cout << guess << std::endl;
				guess[2]++;
			}
			guess[1]++;
		}
		guess[0]++;
	}
	return 0;
}