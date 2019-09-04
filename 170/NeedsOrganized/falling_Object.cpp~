//this program displays the status of a falling object in columns

#include<iostream>
#include<iomanip> // setw()

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ios_base;

int main()
{
	const double GRAVITY = 9.81; 
	double Height;
	double OriginalHeight;
	double Speed;
	double DistanceTravled = 0;

	cout << "Height: ";
	cin >> Height;
	cin.ignore();
	
	OriginalHeight = Height;

	cout.precision(3); // 3 significant figures
	cout.setf(ios_base::fixed); //display out to cout.precision() decimal
	                            //  places, even if not a significant figure
	
	cout << endl << setw(10) << "Time:"; //move output 10 widths
	cout << setw(10) << "Speed:";
	cout << setw(10) << "Height:" << endl;

	for(double Time = 0;Height > 0;Time = Time + .01)
	{
		Speed = GRAVITY * Time;
		DistanceTravled = Speed/2 * Time;
		Height = OriginalHeight - DistanceTravled;
		if(Height >= 0)
		{

		    cout << setw(10) << Time;
		    cout << setw(10) << Speed;		
		    cout << setw(10) << Height << endl;
        }
        else
        {
            cout << "Hit the ground!";
        }
    }
    cin.get();
    return 0;
}





