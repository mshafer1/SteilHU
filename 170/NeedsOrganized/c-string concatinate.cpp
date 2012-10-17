//this file contains three mehtods of concatinating a string
#include<iostream>
using namespace std;

int length(char s[])
{
	int length = 0;

	while(s[length] != '\0')
	{
		length++;
	}
	return length;
}

void copy( char destination[], const char source[] )
{
	int i;
	for(i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

void concatinate( char Destination[], const char Source[] )
{
	int i = length(Destination);
	int j = 0;

	while(Source[j] != '\0')
	{
		Destination[i] = Source[j];
		j++;
		i++;
	}
	Destination[i] = '\0';
}


//void concatinate( char destination[], const char source[] )
//{
//	int destinationLength = length(Destination);
//	int sourceLength = length(Source);
//
//	for(int i = destinationLength, int j = 0;
//		j <= SourceLength; 
//		i++, j++)
//	{
//		Destination[i] = Source[j];
//	}
//}

//void concatinate(char destination[], const char source[])
//{
//	int i;
//	int j;
//	for(i = length(destination), j = 0; source[j] != '\0'; i++, j++)
//	{
//		destination[i] = source[j];
//	}
//	destination[i] = '\0';
//}

//void concatinate( char destination[], const char source[] )
//{
//	int destinationLength = length(Destination);
//	copy(Destination + destinationLength, Source);
//}

void main()
{
	char s[100] = "bob";
	char s2[100] = "by";
	concatinate(s,s2);
	cout << s;
}
