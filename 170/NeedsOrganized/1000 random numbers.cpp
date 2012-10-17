#include<iostream>
#include<time.h>
using namespace std;

void main()
{
	srand(time(0));
	for(int i = 0; i < 1000; i++)
	{
		cout << rand() << endl;
	}
}

