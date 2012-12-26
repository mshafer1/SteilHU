//this program introduces the concept of function templates

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename  typeName>
void myswap(typeName& i, typeName& j)
{  
    //  this function template works with all
    //  data types. Behind the scenes, the 
    //  compiler uses this template to make new
    //  functions for different data types
    
	typeName temp = i;
	i = j;
	j = temp;
}

int main()
{
	string x = "Mc";
	string y = "Donalds";
	cout << x << y << endl;

	myswap(x, y);
	cout << x << y << endl;
    
    int i = 1;
    int j = 2;
 	cout << i << j << endl;
 	
 	myswap(i, j); //works with strings, ints, etc
    cout << i << j;
    
    cin.get();
    return 0;
}
