//this program introduces the concept of function overloading
//  function overloading--defining multiple functions with the same name
//      -the compiler decides which to used based on args in function call

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

void fun(float x)
{
    cout << "fun with a float" << endl;
}

void fun()
{
	cout << "Fun with no arguments passed" << endl;
}

void fun(int x, int i)
{
	cout << "Fun with 2 ints" << endl;
}

void fun(int x)
{
	cout << "Fun with an int" << endl;
}

void fun(long x)
{
	cout << "Fun with a long" << endl;
}

//avoid ambiguous functions--experiment by adding new
//  functions to see what works and what doesn't

int main()
{

	long l = 9;
	fun(l);
    
    fun();
    
    float f = 1.5;
	fun(f);
	
	int x = 1;
	fun(x);
	fun(x, x);
	
    cin.get();
    return 0;
}
