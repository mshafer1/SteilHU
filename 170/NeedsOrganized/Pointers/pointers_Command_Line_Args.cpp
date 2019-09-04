//this program introduces the concept of command line arguments
    //run this program in the console, and include an argument string:
    //  ".\folder\program.exe dog"
    //  in this program, "dog" is searched for in a string

#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;



int main(int argc, char* argv[]) //this is how you receive command line arguments
{ 

// argc: count of command line arguments
//   -always at least 1, because the file path is always an argument

// argv: vector(list) of command line arguments
//   -an array of c-style strings
//   -notice that argv is a pointer to pointers. can also be represented as char** argv
//   -argv[0] always contains the path of the executable file
//   -the argv[1], argv[2], etc contain the command line args

	char line[1000];

	if(argc == 2)
	{
		cout << "enter a string to search: ";
		cin.getline(line, 1000);
		    //if you enter "i have a dog" here, and argv[1] contains "dog"
		        //string will be found
		    //if you enter "i have a cat" here, string will not be found
		if(strstr(line,argv[1])!= NULL)
		{   //argv[1] is the c-style string containing
		    //  the string entered at command line
			cout << "found." << endl;
		}
		else
		{
		    cout << "not found." << endl;
		}

	}
	else
	{
		cout << "Invalid arguments. Please enter one string.\n";
	}
	cin.get();
	return 0;
}
