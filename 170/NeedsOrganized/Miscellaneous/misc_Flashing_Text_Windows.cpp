//this program displays flashing text on a Windows machine

#include<iostream>
#include<time.h>

using std::cout;

int main()
{
	time_t t;
	for(int i = 0; i < 3; i++)
	{
		system("cls"); //clears the console screen (Windows)
		t = time(NULL);
		while(time(NULL) == t)
		{
			cout << "\a";
		}
		cout << "Hello World";
		t = time(NULL);
		while(time(NULL) == t);
	}
	return 0;
}
