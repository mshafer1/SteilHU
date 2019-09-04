#include<iostream>
#include<math.h>
#include<time.h>
#include<cstdlib>
#include<conio.h>
#include<string>

using namespace std;

int main()
{
	do
	{
		system("Cls");
		const double GRAVITY = -9.81;
		double angle;
		double initialVelocity;
		double xVelocity;
		double yVelocity;
		double yInitialVelocity;
		double yDistanceTotal;
		double yDistance = 0;
		double xDistance;
		double highestPoint = 0;
		srand((unsigned int)time(0));
		int enemyPlacement = ((rand()% 1000) + 1);
		int wall = ((rand()% 100) + 1);
		int chances = ((rand()% 10) + 1);
		int wind = (rand()% 2);
		int windSpeed = ((rand()% 50) + 1);
		string windDirection;
		cout.precision(2);
		cout.setf(ios_base::fixed);
		int windSpeedTemp = windSpeed;
		if(wind == 0)
		{
			windDirection = "blowing from behind your back at ";
		}
		else if(wind == 1)
		{
			windDirection = "blowing against you at ";
			windSpeed = -windSpeed;
		}
		
		do
		{
			cout << "shoot the missile over the wall and hit the enemy before they hit you. The      missiles will detonate automatically after 20 seconds or upon impact. The wind  is " << windDirection << windSpeedTemp << " meters per second." << endl;
			cout << endl;
			cout << "Initial speed? (m/s): ";
			cin >> initialVelocity;
			cout << "Trajectory angle? (degrees): ";
			cin >> angle;
			cout << endl;

			angle = angle * 3.14159265359 / 180;
			xVelocity = (initialVelocity * cos(angle)) + windSpeed;
			yInitialVelocity = initialVelocity * sin(angle);
			yDistanceTotal = 2 * (-(yInitialVelocity * yInitialVelocity) / (2 * GRAVITY));
			yVelocity = initialVelocity * sin(angle);
			yDistance = 0;
			double time;

			for(time = 0; yDistance >= 0; time = time + .000001)
			{
				yDistance = yInitialVelocity * time + time * time * GRAVITY / 2;
				//yVelocity = sqrt(yInitialVelocity * yInitialVelocity + 2 * GRAVITY * yDistance);
				xDistance = xVelocity * time * 2;
				if (yDistance > highestPoint)
				{
					highestPoint = yDistance;
				}
			//  cout << "Distance traveled = " << xDistance << endl;
			//	cout << "Height = " << yDistance << endl;
			//	cout << "time = " << time << endl;
			//	cout << "Vertical Velocity = " << yVelocity << endl;
			//	cout << "Horizontal Velocity = " << xVelocity << endl;
			}
			time = time * 2;
			if((int)highestPoint < wall)
			{
				cout << "You did not make it over the wall.";
				_getch();
			}
			else if(time > 20)
			{
				cout << "Your missile exploded in the air " << time - 20 << " seconds before impact.";
				_getch();
			}
			else if(enemyPlacement > (int)xDistance && enemyPlacement > (int)xDistance--)
			{
				cout << "You shot "<< (enemyPlacement - xDistance) << " meters too short.";
				_getch();
			}
			else if(enemyPlacement < (int)xDistance && enemyPlacement < (int)xDistance++)
			{
				cout << "You shot "<< (xDistance - enemyPlacement) << " meters too far.";
				_getch();
			}
			
			system("cls");
			chances--;
		}
		while(enemyPlacement != (int)xDistance && enemyPlacement != (int)xDistance-- && enemyPlacement != (int)xDistance++ && chances >= 0);
		if(enemyPlacement != (int)xDistance && enemyPlacement != (int)xDistance-- && enemyPlacement != (int)xDistance++)
		{
			cout << "The enemy has annihilated you. ";
			_getch();
		}
		else if(enemyPlacement == (int)xDistance || enemyPlacement == (int)xDistance-- || enemyPlacement == (int)xDistance++)
		{
			cout << "you have annihilated the enemy. ";
			_getch();
		}
	}
	while(1 > 0);
	return 0;
}

