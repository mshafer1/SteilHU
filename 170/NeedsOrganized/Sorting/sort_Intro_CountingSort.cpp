//this program demonstrates the counting sort algorithm

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int SIZE = 100000;

void displayList(int list[])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < list[i]; j++ )
		{
			cout << i << endl; //print i as many times as the the counter (list[i]) says
		}
	}
}
int main()
{
	int list[SIZE] = {0};
	//one downside of this algorithm is the relatively large amount of memory used
	int newValue;

	do
	{
		cout << "enter number (-1 to quit):";
		cin >> newValue;
		cin.get(); //flush the carriage return from the istream buffer in the loop rather than later
		if(newValue >= 0 && newValue <= SIZE - 1)
		{
			list[newValue]++; //use the value as an index, store the number of times entered
		}//							-(list[newValue] is a counter)
	}
	while(newValue >= 0 );

	displayList( list );
	cin.get(); //wait for user
	return 0;
}