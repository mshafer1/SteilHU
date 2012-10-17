#include<iostream>

using namespace std;

int main()
{
	int x;
	int y;
	cin >> x;
	cin >> y;

	int max = (x>y)?x:y;
	cout << max << endl;
	cout << ((x>y)?x:y) << endl;
	cout << ((x==y)?"same":"different");

	cout << ((x==y)?"same":((x>y)?"x is greater":"y is greater"));

//	(x > 100)?cout << "big number\n" : cout << "small number\n";

	return 0;
}
