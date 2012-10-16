#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	const double GRAVITY = 9.8;
	double height;
	double speed = 0;
	double time = 0;
	double distanceTraveled = 0;

	cout << "Height?";
	cin >> height;
	
	cout.precision(4);
	cout.setf(ios_base::fixed);

	while(height - distanceTraveled > 0)
	{
		distanceTraveled = time * speed/2;
		cout << setw(10) << time;
		cout << setw(10) << height - distanceTraveled;
		cout << setw(10) << speed << endl;
		time += .001;
		speed = time * GRAVITY;
	}

	//int i = 1;
	//while(i < 1001)
	//{
	//	cout << i << " I will not talk in class" << endl;
	//	i--;
	//	//i += 1;
	//	//i = i + 1;
	//}


	system("Pause");
}
