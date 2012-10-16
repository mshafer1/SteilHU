#include <iostream>
#include <time.h>
 
using namespace std;

//global constants
const int STUDENT_COUNT = 10;
const int ASSIGNMENT_COUNT = 5;

void main()
{
	srand(time(NULL));
	////10 rows by 5 columns
	float grades[STUDENT_COUNT][ASSIGNMENT_COUNT] = {{0,1,2,3,4},{5,7,9,8,7}};

	for(int row = 0; row < STUDENT_COUNT; row++)
	{
		for(int column = 0; column < ASSIGNMENT_COUNT; column++)
		{
			grades[row][column] = 50 + (rand() % 51);
		}
	}

	for(int row = 0; row < STUDENT_COUNT; row++)
	{
		for(int column = 0; column < ASSIGNMENT_COUNT; column++)
		{
			cout << grades[row][column] << " ";
		}
		cout << endl;
	}



	//seeding the random number generator

	//while(true)
	//{
	//	srand(time(NULL));
	//	cout << time(NULL) << endl;
	//	cout << rand() << endl;
	//}
	//cout << rand() << endl;
	cout << RAND_MAX  << endl;
	system("pause");

	int counts[13] = {0};

	int roll = 6;
	counts[roll]++;

}
