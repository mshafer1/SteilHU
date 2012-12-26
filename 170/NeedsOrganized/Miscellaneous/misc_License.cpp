//this program is an example test question and answer

#include<iostream>
#include<string>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

//7.	A witness to a bank robbery recalls that the license number 
//of the get away car was xxx-SUN, where xxx represents 3 letters 
//or digits which were not clearly visible.  The state police have 
//a disk file named LICENSE.DAT which contains information on every 
//license number in the state.  The file is a text file, and each 
//line in the file contains a license number followed by a comma, 
//the name of the vehicle’s owner, and the end of line character.  (20 points)
//
//Note:
//•	There is no space between the license, the comma, and the name.  
//•	No license number may contain a comma.  
//•	Not all license numbers are the same length.
//•	Not all license numbers contain a dash.  
//
//Write a complete C++ program that will print to screen the license number
//and the owner’s name of all licenses that could possibly match the get-away car. 
//(You may use the back of this page.)


int main()
{
	const char FILE_NAME[] = "LICENSE.DAT";

	ifstream fin(FILE_NAME);

	if(!fin.fail())
	{
		while(!fin.eof())
		{
			string line;

			getline(fin,line);

			if(line.find("-SUN,") != string::npos)
			{
				cout << line << endl;
			}
		}

		fin.close();
	}
	else
	{
		cout << "Unable to find " << FILE_NAME << endl;
	}
	
    cin.get();
    return 0;
}
