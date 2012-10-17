#include<iostream>
#include<fstream>

using namespace std;

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

	


	return 0;
}  

