#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

using std::cout;
using std::endl;

void main()
{
	int DieOne;
	int DieTwo;
	
	srand(time(0));

	for (int i = 0; i < 20; i++)
	{
		DieOne = (rand()% 6) + 1;
		DieTwo = (rand()% 6) + 1;

		cout << "Die One is " << DieOne << " ";
		cout << "Die Two is " << DieTwo << endl;
		
		_getch();
		system("cls");
	}
}