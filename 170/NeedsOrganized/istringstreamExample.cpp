#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Notice the if statement before displaying the word.  
//The last word we get from the string stream is empty and should not be used.

void main()
{
	string s;
	getline(cin,s);
	istringstream iss(s);

	do
	{
		string word;
		iss >> word;
		if(word.length() > 0)
		{
			cout << word << endl;
		}
	} while (iss);
}