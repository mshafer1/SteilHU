#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	int x[] = {1,4,6,3,2,2};

	char a[10] = {'a','b','c'};
	cout << a << endl;

	char b[] = "bob";
	cout << b << endl;


}

//c-style string

//using namespace std;
//
//const int SIZE = 100000;
//
//void displayList(int list[])
//{
//	for(int i = 0; i < SIZE; i++)
//	{
//		for(int j = 0; j < list[i]; j++ )
//		{
//			cout << i << endl;
//		}
//	}
//}
//

//void main()
//{
//	int list[SIZE] = {0};
//	int newValue;
//
//	do
//	{
//		cout << "enter number:";
//		cin >> newValue;
//		if(newValue >= 0 && newValue <= SIZE - 1)
//		{
//			list[newValue]++;
//		}
//	
//	}
//	while(newValue >= 0 );
//
//	displayList( list );
//}
