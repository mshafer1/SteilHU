//this program dynamically allocates memory with "new"
//  dynamic vs. local 
//  "delete", "delete []"

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{


	int x = 7; //x is a local integer

	//NULL the address 0 (points to nothing)
	int* px = NULL; //px is a pointer to an integer
		//px contains the address of an integer
		//currently points to nothing

	//& means "the address of"
	px = &x;

	cout << "x: " << x << endl;
	cout << "px (address of x): " << px << endl;
	
	if(px != NULL) 
	{ // make sure your pointers point to something before you use them
		cout << "*px (what is stored at px): " << *px << endl;
	}

	int* pInt = NULL;
//  *pInt = 7; 
//      DO NOT DO THIS, goes out of bounds. First we need to get memory.

	pInt = new int;
	    //dynamically allocates space for an int
	        //pInt now points to usable space.
	        //We can store an int there.

	cout << "pInt (new int address): " << pInt << endl;

	cout << "*pInt (what is at pInt (garbage)): " << *pInt << endl;
	    //pInt could be anything. OS gave the program memory to use.
	*pInt = 10;
	    //does not go out of bounds, because we dynamically allocated memory.
	cout << "*pInt (what is at pInt): " << *pInt << endl;

	delete pInt; //always delete every time you are done with a variable stored in
	             //     dynamically allocated memory.
	
	int* pArray = NULL; // as opposed to int Array[10];

	cout << "Array size? ";
	cin >> x;
	cin.ignore();

	pArray = new int[x];
        //dynamic allocation lets us determine the size of
        //  an array during runtime
	for(int i = 0; i < x; i++)
	{
		cout << "enter an int: ";
		cin >> pArray[i];
		cin.ignore();
		//same as "cin >> *(pArray + i); "
	}
	cout << "You entered: \n";
	for(int i = 0; i < x; i++)
	{
		cout << pArray[i] << endl;
	}

    delete [] pArray; //this is the proper syntax for deleting
                      //    a dynamically allocated array
    cin.get();
    return 0;
}
//      Why do you have to delete?
//
//if you do not use "delete", you have a memory leak. "delete" 
//  gives the memory back to the OS (deallocation). If you do 
//  not give it back, the operating system will not be able 
//  to use it again until a reboot.







