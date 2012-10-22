//Dana Steil
//Comp 170 

#include<iostream>
using namespace std;

void main()
{
	double grade;

	cin >> grade;

	grade = grade + .5;

	if(grade >= 90)
	{
		cout << "A" << endl;
	}
	else if(grade >= 80)
	{
		cout << "B" << endl;
	}
	else if(grade >= 70)
	{
		cout << "C" << endl;
	}
	else if(grade >= 60)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "F" << endl;
	}

	//if(grade >= 90)
	//{
	//	cout << "A" << endl;
	//}
	//else
	//{
	//	if(grade >= 80)
	//	{
	//		cout << "B" << endl;
	//	}
	//	else
	//	{
	//		if(grade >= 70)
	//		{
	//			cout << "C" << endl;
	//		}
	//		else
	//		{
	//			if(grade >= 60)
	//			{
	//				cout << "D" << endl;
	//			}
	//			else
	//			{
	//				cout << "F" << endl;
	//			}
	//		}
	//	}
	//}
}

