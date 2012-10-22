#include<iostream>
#include<fstream>
#include<string>
using namespace std;


struct Arkansan
{
	//data members
	//member variables
	//attributes
	string name;
	bool bornAboveI40;
	short teethCount;
	long carsOnBlocks;
	//....

	//constructor
	Arkansan( string newName)
	{
		name = newName;
		bornAboveI40 = true;
		teethCount = 0;
		carsOnBlocks = 2;
	}

	//constructor
	Arkansan()
	{
		name = "Joe Bob";
		bornAboveI40 = true;
		teethCount = 0;
		carsOnBlocks = 2;
	}

	//destructor
	~Arkansan()
	{
		cout << name << " died" << endl;
	}

	//member function
	void display()
	{
		cout << name << endl;
		cout << carsOnBlocks << endl;
		//...
	}
};

ostream& operator<<(ostream& out, Arkansan& a)
{
	cout << a.name << endl;
	cout << a.carsOnBlocks << endl;
	return out; 
}

void main()
{
	Arkansan* pa = new Arkansan("bob");
	delete pa; 
	{
		Arkansan a1[10];
	}
	cout << "code after scope" << endl;

	Arkansan a;
	cout << a;

}











