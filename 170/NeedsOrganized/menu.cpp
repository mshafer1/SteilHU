#include<iostream>

using namespace std;

int main()
{
	char c;
	cout << "(a)dd\n";
	cout << "(s)ubtract\n";
	cin >> c;

	switch(tolower(c))
	{
		case 'a':
			cout << "add\n";
			break;
		case 's':
			cout << "subtract\n";
			break;
		default:
			cout << "error message\n";
			break;
	}

	return 0;
}
