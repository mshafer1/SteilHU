#include<iostream>
#include<iomanip>
using namespace std;
//by value vs. by reference
void trade(int& i, int& j)
{
	int thomas = i;
	i = j;
	j = thomas;
	cout << i << " " << j << endl;
}

int LeastCommonMultiple(int x, int y)
{
	int result = 1;

	//while(!(result % x == 0 && result % y == 0 ))
	while(result % x != 0 || result % y != 0 )
	{
		result++;
	}

	return result;
}


void main()
{
	int x = 9;
	int y = 14;
	int answer;
	cout << LeastCommonMultiple(x, y) << endl;

	//int& stuff = x;
	//stuff = 999234;

	trade(x,y);
	
	double y = pow(4.5,3);

//	trade(x,8); // will not work

	cout << x << " " << y << endl;

	system("pause");
}
