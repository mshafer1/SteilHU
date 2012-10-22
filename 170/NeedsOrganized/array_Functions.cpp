#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;


void fun(int B[][5][6])
{
	cout << "In the 3d array function" << endl;
}

void fun(int B[][6])
{
	cout << "In the 2d array function" << endl;
}

void fun(int B[])
{
	cout << "In the 1d array function" << endl;
}

void fun(int B)
{
	cout << "In the element function" << endl;
}


void main()
{
	int D3[4][5][6] = {0};
	int D2[5][6] = {0};
	int D1[6] = {0};
	int x = 9;

	fun(D3);
	fun(D2);
	fun(D1);
	fun(x);

	fun(D3[0]);
	fun(D2[0]);
	fun(D1[0]);

	fun(D3[0][0]);
	fun(D2[0][0]);
	
	fun(D3[0][0][0]);
}
