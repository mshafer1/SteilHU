//this program uses a function to find the absolute value of a number

#include<iostream>

using std::cout;
using std::cin;

float absoluteValue( float x )
{
	float result = x;

	if( x < 0 )
	{
		result = -1 * x;
	}

	return result;
}

int main()
{
    cout << absoluteValue(-10);
    
    cin.get();
    return 0;
}
