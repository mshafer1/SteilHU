#include<iostream>
#include<cstdlib>

using std::cout;
using std::cin;

int main()
{
	char A[100];
	int x = 99;
	//the itoa (integer to ascii) funtion takes three parameters
	//1) the number you want to convert to a string
	//2) the string you want to store the result in
	//3) the base you are using (normally 10)
	_itoa(x,A,10);

	cout << A;
	
    cin.get();
    return 0;
}
