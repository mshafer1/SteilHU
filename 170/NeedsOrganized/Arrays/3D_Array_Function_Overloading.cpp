// this program shows how to create and use multiple functions 
// with the same name, or function overloading. When overloaded
// functions exist, the compiler determines which function to use
// based on the arguments of the function call.

#include<iostream>
#include<iomanip>
#include<ctime>

using std::cout;
using std::endl;


void fun(int B[][5][6])
{
	cout << "In the 3d array function" << endl << endl;
}

void fun(int B[][6])
{
	cout << "In the 2d array function" << endl << endl;
}

void fun(int B[])
{
	cout << "In the 1d array function" << endl << endl;
}

void fun(int B)
{
	cout << "In the element function" << endl << endl;
}




int main()
{
	int D3[4][5][6] = {0};
	int D2[5][6] = {0};
	int D1[6] = {0};
	int x = 9;

	cout << "\ncalling fun(D3):\n"; 
	fun(D3);
	
	cout << "calling fun(D2):\n"; 
	fun(D2);
	
	cout << "calling fun(D1):\n"; 
	fun(D1);
	
	cout << "calling fun(x):\n"; 
	fun(x);

	cout << "calling fun(D3[0]):\n"; 
	fun(D3[0]);
	
	cout << "calling fun(D2[0]):\n";
	fun(D2[0]);
	
	cout << "calling fun(D1[0]):\n";
	fun(D1[0]);

	cout << "calling fun(D3[0][0]):\n";
	fun(D3[0][0]);
	
	cout << "calling fun(D2[0][0]):\n";
	fun(D2[0][0]);
	
	cout << "calling fun(D3[0][0][0]):\n";
	fun(D3[0][0][0]);
	
	return 0;
}
