#include<iostream>
#include<string>
using namespace std;

//argc - count of command line arguments passed in this time
//argv - vector(list) of command line arguments
//an array of c-style strings
int main(int argc, char* argv[])
{
	char line[1000];

	if(argc == 2)
	{
		int i = 0;
		while(!cin.eof())
		{
			cin.getline(line,1000);
			if(strstr(line,argv[1])!= NULL)
			{
				cout << line << endl;
			} 
			i++;
		}	
	}
	else
	{
		cout << "Usage: perg search\n";
	}
	return 0;
}
