#include<iostream>

using namespace std;

void beep( int timesToBeep )
{
	for(int i = 0; i < timesToBeep; i++)
	{
		cout << "\a";
	}
}


void main()
{
	beep(10);
}