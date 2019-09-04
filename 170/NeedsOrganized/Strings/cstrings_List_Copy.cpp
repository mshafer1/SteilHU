//this program stores inputs from the user as an
//array of c-style strings (2D array), and then
// copies the contents into an identical 2D array

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_NAMES = 5;

void copyString(char* destination,const char* source)
{
	int i = 0;
	while(source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

void copyNameList(char destination[][20],const char source[][20])
{
	for(int i = 0; i < MAX_NAMES; i++)
	{
		copyString(destination[i], source[i]);
	}
}

int main()
{
	char nameList[MAX_NAMES][20];
	cout << "enter " << MAX_NAMES << " last names to add to the list:\n";
	for(int i = 0; i < MAX_NAMES; i++)
	{
		cin >> nameList[i];
		cin.ignore();
		//remember, this only works with one 
		//   word at a time, because cin 
	}	//   stops at whitespace

	char nameList2[MAX_NAMES][20];

	copyNameList(nameList2,nameList);
	cout << "Copy of list: " << endl;
	for(int i = 0; i < MAX_NAMES; i++)
	{
		cout << nameList2[i] << endl;
	}

	cin.get();
	return 0;
}
