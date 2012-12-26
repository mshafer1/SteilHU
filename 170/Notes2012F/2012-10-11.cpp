#include<iostream>
using namespace std;

//complete this function to retrun true if the query string is found
//in the source string.  It does not have to be case insensitive.
bool contains(char source[], char query[])
{
	bool result = false;

	return result;
}

void main()
{
	//strlen(s) returns an int
	//strcpy(destination,source) void
	//strncpy
	//strcat(destination,source) void
	//strncat
	//strcmp(s1,s2) return -1, 0, 1
	//strncmp
	//stricmp
	//strnicmp
	//strstr
	
	char s1[100];
	char s2[100];
	cin.getline(s1,100); //bob
	cin.getline(s2,100); //what about bob
	cout << strstr(s2,s1) << endl;
	
	//if(strnicmp(s1,s2,3) == 0)
	//{
	//	cout << "Same" << endl;
	//}


	//if(strncmp(s1,s2 + strlen(s2) -strlen(s1),strlen(s1))== 0)
	//{
	//	cout << "Same" << endl;
	//}

	//strncpy(s1 + 2,s2 + 3 ,3);
	//s1[3] = '\0';	
	//cout << s1 << endl;
}