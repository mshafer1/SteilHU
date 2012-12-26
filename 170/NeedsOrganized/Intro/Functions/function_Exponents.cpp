//this program finds x^y

#include<iostream>

using std::cout;
using std::cin;

void displayPower(float x, int y)
{
	float result = 1;

	if(y >= 0)
	{
		while(y > 0)
		{
			result = result * x; 
			y--;
		}
	}
	else
	{
		while(y < 0)
		{
			result = result / x; 
			y++;
		}
	}

	cout << result;


}

int main()
{
	displayPower(3, 6);
	
	cin.get();
	return 0;
}
