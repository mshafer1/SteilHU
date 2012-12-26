#include<iostream>
#include<fstream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int main()
{
	ifstream fin("signup.txt");

	char line[300];

	do
	{
		fin.getline(line, 300);
		char* pComma = strchr(line,',');

		if(pComma != NULL)
		{
			pComma++;
			while(*pComma != ',')
			{
				cout << *pComma;
				pComma++;
			}
			cout << endl;
		}
	}
	while( !fin.eof() );

	cin.get();
	return 0;
}  

