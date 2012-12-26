#include<iostream>
using namespace std;
// {} define a scope
// scope - define the life of a variable
void main()
{
	int age;
	cout << "Enter your age? ";
	cin >> age;

	//if(age <= 1) 
	//{
	//	cout << age << " is an Infant" << endl;
	//}
	//
	//do not do this... this will compare a 1 or 0 with 3
	////if(1 < age <= 3 )
	//if(age <= 3 && age > 1)
	//{
	//	cout << "Toddler" << endl;
	//}

	//if(age <= 12 && age > 3)
	//{
	//	cout << "Child" << endl;
	//}

	if(age <= 1) 
	{
		//yes path
		cout << age << " is an Infant" << endl;
	}
	else
	{
		//no path
		if(age <= 3)
		{
			cout << "Toddler" << endl;
		}
		else
		{
			if(age <= 12)
			{
				cout << "Child" << endl;
			}
		}
	}

	if(age <= 1) 
	{
		cout << age << " is an Infant" << endl;
	}
	else if(age <= 3)
	{
		cout << "Toddler" << endl;
	}
	else if(age <= 12)
	{
		cout << "Child" << endl;
	}


	system("Pause");
}
