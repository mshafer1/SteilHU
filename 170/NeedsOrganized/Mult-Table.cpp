#include<iostream>
#include<iomanip>

using namespace std;

void main()
{
	int x = 1;

	while(x <= 10)
	{
		int y = 1;

		while(y <= 10)
		{
			int z = x * y;

			cout << setw(10) << z;

			//if (z < 10)
			//{
			//	 cout << "   ";
			//}
			//else if (z < 100)
			//{
			//	cout << "  ";
			//}
			//else if (z < 1000)
			//{
			//	cout << " ";
			//}

			y++;
		}
		cout << endl;
		x++;
	}
}
