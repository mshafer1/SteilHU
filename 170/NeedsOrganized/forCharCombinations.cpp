#include<iostream>
using namespace std;

void main()
{
	int i = 0;
	for(char c1 = 'A'; c1 <= 'Z'; c1++)
	{
		for(char c2 = 'A'; c2 <= 'Z'; c2++)
		{
			for(char c3 = 'A'; c3 <= 'Z'; c3++)
			{
				cout << c1 << c2 << c3 << endl;
			}
		}
	}
}