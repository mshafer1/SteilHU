//this program makes the computer beep

#include<iostream>

using std::cout;

void beep( int timesToBeep )
{
	for(int i = 0; i < timesToBeep; i++)
	{
		cout << "\a"; // "beep" escape character
	}
}


int main()
{
	beep(10);
	
    return 0;

}
