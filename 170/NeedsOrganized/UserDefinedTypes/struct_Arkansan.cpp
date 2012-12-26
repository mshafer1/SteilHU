// this program explores:
//	1. constructors
//		-multiple constructors
//	2. destructors
//		-scope
//	3. operator overloading
//	4. -> operator

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

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
		cout << name << " is born\n";
	}

	//constructor
	Arkansan()
	{
		name = "a nameless guy"; // this constructor used when no arguments at declaration
		bornAboveI40 = true;
		teethCount = 0;
		carsOnBlocks = 2;
		cout << name << " is born\n";
	}

	//destructor. Always has tilde and no arguments.
	~Arkansan()
	{
		cout << name << " died" << endl;
	}

	//member function
	void display()
	{
		cout << "(display() function called)\n";
		cout << "name: " << name << endl;
		cout << "number of teeth:" << teethCount << endl;
		cout << "cars on blocks: " << carsOnBlocks << endl << endl;
	}
};

// global overload on std::ostream's << operator.
// it's a special kind of function.
// this function is only called when an Arkansan object is used.
ostream& operator << (ostream& out, Arkansan& a)
{
	cout << "\n(operator overload function called)\n";
	cout << "name: "<< a.name << endl;
	cout << "number of teeth:" << a.teethCount << endl;
	cout << "cars on blocks: " << a.carsOnBlocks << endl << endl;
	return out; 
}

int main()
{
	cout << endl;
	
	Arkansan* joeBob = new Arkansan("Joe Bob"); //new always calls constructor, Joe Bob is born
													
	
	joeBob -> teethCount = 3;	// joeBob is a pointer; the -> operator allows access to	
	joeBob -> display(); 		//members of the object pointed to.
	
	
	delete joeBob; // delete always calls destructor, Joe Bob dies
	
	cout << endl << "going into a scope...\n";
	{
		Arkansan arkansanArray[10]; //array of arkansans. Constructor is called for each element
		
		(arkansanArray[3]).name = "Jim Tom";
		cout << "(arkansanArray[3] is now named Jim Tom)\n";
	} 
	// when an object goes out of scope, the destructor is called.
		// destructors are called for each element of arkansanArray.
	
	cout << "...scope left.\n" << endl;

	Arkansan namelessGuy;	//constructor called
	namelessGuy.name = "Henry Steve";
	
	Arkansan jerryLou("Jerry Lou");
	cout << jerryLou;	// operator overload function called
	
	return 0;
} //scope left, so Henry Steve and Jerry Lou died











