#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int age;

	//cout << "Age? ";
	//cin >> age;

	//while(age < 0 || age > 117)
	//{
	//	cout << "Age? ";
	//	cin >> age;
	//}

	//indeterminate
	//determinate - counted
	//infinite
	//do
	//{
	//	cout << "Age? ";
	//	cin >> age;
	//}
	//while(age < 0 || age > 117);
	
	for(int i = 0; i <= 9; i ++)
	{
		cout << i * 0 << "\t";
		cout << i * 1 << "\t";
		cout << i * 2 << "\t";
		cout << i * 3 << "\t";
		cout << i * 4 << "\t";
		cout << i * 5 << "\t";
		cout << i * 6 << "\t";
		cout << i * 7 << "\t";
		cout << i * 8 << "\t";
		cout << i * 9 << endl;
	}
	//cout << i << endl;



	system("Pause");
}
