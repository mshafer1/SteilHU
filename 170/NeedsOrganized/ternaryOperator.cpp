#include<iostream>
using namespace std;

void main()
{
	int i;
	cin >> i;

	(i < 10)? cout << "yoohoo" : cout << "boo";

	i = (i < 10)? 0 : 100;

	cout << endl << i << endl;
}