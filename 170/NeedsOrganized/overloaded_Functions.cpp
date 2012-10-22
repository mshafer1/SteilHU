#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int fun(float x)
{
	return 1;
}

void fun()
{
	cout << "Fun" << endl;
}

void fun(int x, int i)
{
	cout << "Fun with an int" << endl;
}

void fun(int x)
{
	cout << "Fun with an int" << endl;
}

void fun(long x)
{
	cout << "Fun with an long" << endl;
}


struct CExample
{
public:
	int x;


	//constructor
	CExample()
	{
		x = 0;
	}
	CExample(int newx)
	{
		x = newx;
		Display();
	}

private:
	void Display()
	{
		cout << x << endl;
	}
};

void InitializeExample(CExample& e)
{
	e.x = 0;
}


void main(int argc, char* argv[])
{
	CExample e1;
	CExample e2(9);
	InitializeExample(e1);
	
	// Cannot Access Private Function
	//e1.Display();
	//e2.Display();

	long l = 9;

	fun(8l);
	fun(l);

}