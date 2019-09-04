//this short program shows how to clear the console screen in the Windows Command Line

#include<iostream>
#include<stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	float number;
	number = 0;
	do
	{
		system("cls");	// system("cls") is a Windows-specific command that
						// clears the console screen
						
		cout << "Enter a number, it will disappear (0 to quit):";
		cin >> number;		
	
		
	}while(number != 0);

	return 0;
}
