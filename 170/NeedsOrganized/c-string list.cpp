#include<iostream>
#include<string>

using namespace std;

void CopyString(char* Destination,const char* Source)
{
	int i = 0;
	while(Source[i] != '\0')
	{
		Destination[i] = Source[i];
		i++;
	}
	Destination[i] = '\0';
}

void CopyNameList(char Destination[][20],const char Source[][20], int Names)
{
	for(int i = 0; i < Names; i++)
	{
		CopyString(Destination[i], Source[i]);
	}
}

void main()
{
	char NameList[5][20];

	for(int i = 0; i < 5; i++)
	{
		cin >> NameList[i];
	}

	char NameList2[5][20];

	CopyNameList(NameList2,NameList,5);

	for(int i = 0; i < 5; i++)
	{
		cout << NameList2[i] << endl;
	}
}