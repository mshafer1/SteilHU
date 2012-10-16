#include<iostream>
#include<iomanip>
using namespace std;

//functions
//make program easier to read
//modular - build clear components
//reusability

//parameter
void fun(int funCount)
{
	for(int i = 0; i < funCount; i++)
	{
		cout << "now we are having fun" << endl;
	}
}

//name void functions with verbs or verbNoun combinations
void displayTimesTable(int rows, int columns)
{
	for(int r = 1; r <= rows; r++)
	{
		for(int c = 1; c <= columns; c++)
		{
			cout << setw(4) <<  r * c;
		}
		cout << endl;
	}
}

int seven()
{
	return 7;
}

int product(int x, int y)
{
	int result = x * y;
	return result;
}

int power(int x, int y)
{
	int result = 1;

	for(int i = 0; i < y; i++)
	{
		result = result * x;
	}

	return result;
}

void main()
{
	//arguments 9, 1
	//fun(9);
	//
	//displayTimesTable(8,5);
	//displayTimesTable(5,8);
	//cout << 1 + seven() + 9 << endl;
	//cout << product(8,11) << endl;
	//cout << power(5,1) << endl;
	int x;
	int y;
	cin >> y;
	cin >> x;
	int r = power(3,x);
	cout << power(y,r) << endl;
	cout << pow(4.0, 5) << endl;

	system("pause");
}
