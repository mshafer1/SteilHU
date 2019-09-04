//this program introduces the ternary operator ?:
//  three operands
//  

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int i;
	cout << "Enter a number: ";
	cin >> i;
	cin.ignore();

	(i < 10)? cout << "yoohoo" : cout << "boo";
	//same as:
	//  if(i < 10) 
	//  {
	//      cout << "yoohoo";
	//  }
	//  else
	//  {
	//      cout << "boo";
	//  }

	i = (i < 10)? 0 : 100;
	// if true, i = 0. if false, i = 100	
	cout << endl << i;
	
    cin.get();
    return 0;
}
