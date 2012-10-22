# include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

const int MAX_PEOPLE = 20;

void InitializePeople(int People[])
{
	for (int *p = People; p < People + MAX_PEOPLE; p++)
	{
		*p = rand()%9000 + 1000;
	}
}

//void InitializePeople(int People[])
//{
//	for (int i = 0; i < MAX_PEOPLE; i ++)
//	{
//		People[i] = rand()%9000 + 1000;
//	}
//}

void ShowPeople(int People[])
{
	for (int i = 0; i < MAX_PEOPLE; i ++)
	{
		cout << People[i] << endl;
	}
}
//void ShowPeople(int People[])
//{
//	for (int i = 0; i < MAX_PEOPLE; i ++)
//	{
//		cout << People[i] << endl;
//	}
//}

void Swap(int People[], int i, int j)
{
	int temp = *(People + i); // People[i]
	*(People + i) = *(People + j);
	*(People + j) = temp;
}

void main()
{

	int People[MAX_PEOPLE];
	bool Sorted = false;

	srand((unsigned int) time(NULL));

	InitializePeople(People);

	for (int i = 0; (i < MAX_PEOPLE - 1) && !Sorted; i++)
	{
		Sorted = true;

		for(int k = 0; k < (MAX_PEOPLE - 1 - i); k ++)
		{
			if (People[k] < People[k+1])
			{
				Swap(People, k, k+1);
				Sorted = false;
			}
		}
	}

	ShowPeople(People);
}









