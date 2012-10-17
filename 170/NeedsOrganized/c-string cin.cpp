#include<iostream>
using namespace std;

void main()
{
	char Name[10];

	//cin >> ignores all leading white space
	//stops at white space
	//causes out of bounds error when many chars are placed in the array
	cin >> Name;
	cout << Name << endl;

	int p;
	cin >> p;
}
