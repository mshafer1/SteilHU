#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;

void main()
{
	const double GRAVITY = 9.8; 
	double Height;
	double OriginalHeight;
	double Speed;
	double DistanceTravled = 0;

	cout << "Height: ";
	cin >> Height;
	OriginalHeight = Height;

	cout.precision(3);
	cout.setf(ios_base::fixed);

	for(double Time = 0;Height > 0;Time = Time + .01)
	{
		Speed = GRAVITY * Time;
		DistanceTravled = Speed/2 * Time;
		Height = OriginalHeight - DistanceTravled;
		 
		cout << setw(10) << Time;
		cout << setw(10) << Speed;
		cout << setw(10) << Height << endl;
		
	}

}





