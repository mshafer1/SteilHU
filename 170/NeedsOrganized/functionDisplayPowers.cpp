#include<iostream>
using namespace std;

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

	cout << result << endl;


}

void main()
{
	displayPower(3, 6);
}