//this program contains three methods of concatinating a c-style string,
	//without using the built-in functions.
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

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

//Two other ways:

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

int main()
{
	cout << "String 1: ";
	char s1[50] = {'\0'};
	cin.get(s1, 50); //get up to 50 chars, store in s1
	cin.ignore(); //ignore the carriage return
	
	cout << "String 2: ";
	char s2[50] = {'\0'};
	cin.get(s2, 50);
	cin.ignore();
	
	concatinate(s1,s2); //add s2 to the end of s1
	cout << endl << s1;
	
	cin.get();
	return 0;
}
