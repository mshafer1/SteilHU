#include<iostream>

using namespace std;

void main()
{
	int Numbers;

	cout << "How many number do you want to average? ";
	cin >> Numbers;

	float Total = 0;

	int CurrentNumber = 0;
	float NextNumber;

	while(CurrentNumber < Numbers)
	{
		cout << "Enter the " << CurrentNumber + 1;
		
		int OnesPlace = (CurrentNumber + 1) - ((CurrentNumber + 1)/10 * 10);
		int TeensPlace = (CurrentNumber + 1) - ((CurrentNumber + 1)/100 * 100);

		if(TeensPlace == 11 || TeensPlace == 12 || 
		 TeensPlace == 13 || OnesPlace > 3 || OnesPlace == 0)
		{
			cout << "th number ";
		}
		else if(OnesPlace == 1)
		{
			cout << "st number ";
		}
		else if(OnesPlace == 2)
		{
			cout << "nd number ";
		}
		else if(OnesPlace == 3)
		{
			cout << "rd number ";
		}

		cin >> NextNumber;

		Total = Total + NextNumber;
		CurrentNumber++;
	}

	
	if(Numbers > 0)
	{
		cout << "The average is " << Total/Numbers << endl;
	}
	else
	{
		cout << "No numbers entered" << endl;
	}
}