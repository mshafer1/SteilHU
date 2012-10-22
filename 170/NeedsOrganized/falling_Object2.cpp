#include<iostream>
#include<iomanip>

using namespace std;

void main()
{
	const double GRAVITY = 9.8;
	double originalHeight;
	double height;
	double speed = 0;
	double time = 0;

	cout << "From what height would you like to fall? ";
	cin >> originalHeight;
	height = originalHeight;

	cout.precision( 2 );
	cout.setf( ios_base::fixed );

	//cout << "Time      Speed          Height" << endl;
	cout << setw(10) << "Time";
	cout << setw(15) << "Speed";
	cout << setw(15) << "Height" << endl;

	while( height > 0)
	{
		speed = GRAVITY * time;
		height = originalHeight - ( ( speed / 2 ) * time );

		cout << setw(10) << time;
		cout << setw(15) << speed;
		cout << setw(15) << height  << endl;

		time = time + .001;
	}
}




