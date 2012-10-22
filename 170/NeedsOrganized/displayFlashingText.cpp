#include<iostream>
#include<time.h>

using namespace std;

void main()
{
	time_t t;
	for(int i = 0; i < 3; i++)
	{
		system("cls");
		t = time(NULL);
		while(time(NULL) == t)
		{
			cout << "\a";
		}
		cout << "Hello World";
		t = time(NULL);
		while(time(NULL) == t);

	}
}