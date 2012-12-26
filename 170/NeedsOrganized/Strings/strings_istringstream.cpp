//this program demonstrates the use of an istringstream

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::istringstream;
using std::string;

int main()
{
	string s;
	cout << "type a sentence: ";
	getline(cin,s);
	istringstream iss(s);  //iss can be used line cin now, it contains the data from s

	do
	{
		string word;
		iss >> word;  //reading from the string stream into a string

		//Notice the if statement before displaying the word.  
		//The last word we get from the string stream is empty and should not be used.
		if(word.length() > 0)
		{
			cout << word << endl;
		}
	}
	while (iss);  //this will be false after an attempt to read from an empty stream
	// this could be while(word.length() > 0);
    
    cin.get();
    return 0;
}
