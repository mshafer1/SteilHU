//Dana Steil
//Comp 170 



#include<iostream>

using namespace std;

void main()
{
	int i;


	cin >> i;

	//logical condition
	//logical and  &&
	//logical or   ||
	if(i >= 0  && i <= 100)
	{
		cout << "Howdy" << endl;
	}
	else
	{
		if(i > 100 && i <= 200)
		{
			cout << "Hi" << endl;
		}
		else
		{
			cout << "Go away" << endl;
		}
	}

	if(i >= 0  && i <= 100)
	{
		cout << "Howdy" << endl;
	}
	else 
	{
		if(i > 100 && i <= 200)
		{
			cout << "Hi" << endl;
		}
		else 
		{
			if(i > 200 && i <= 300)
			{
				cout << "Hi Yall" << endl;
			}
			else
			{
				if(i > 300 && i <= 400)
				{
					cout << "Go Bisons" << endl;
				}
				else
				{
					cout << "Go away" << endl;
				}
			}
		}
	}
	//if(i == 7)
	//{
	//	cout << "That is my favorite number" << endl;
	//}

	//if(i = 0)
	//{
	//	cout << "That is my favorite number" << endl;
	//}

	//if(0 == 7)
	//{
	//	cout << "That is my favorite number" << endl;
	//}
	//else
	//{
	//	cout << "I do not like that number" << endl;
	//}	


}
