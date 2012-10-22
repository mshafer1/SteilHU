#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main()
{
	int listSize = 5;
	int nameCount = 0;
	string* names = new string[listSize];

	do
	{
		//cin >> names[nameCount];
		getline(cin,names[nameCount]);
		if(names[nameCount] != "exit")
		{
			nameCount++;
			if(nameCount >= listSize)
			{
				//we need a bigger list
				listSize = listSize * 2;
				string* newNames = new string[listSize];
				for(int i = 0; i < nameCount; i++)
				{
					newNames[i] = names[i];
				}
				delete[] names;
				names = newNames;
			}
		}	
	}
	while( names[nameCount] != "exit");

	for(int i = 0; i < nameCount; i++)
	{
		cout << names[i] << endl;
	}

	cout << listSize << endl;
	delete[] names; 
}