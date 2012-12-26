#include<iostream>
#include<string>
using namespace std;

// write a funtion named isSameString
//it should take two c-style string as arguments and then
//return true if they have the same characters, false otherwise

bool isSameString(char s1[], char s2[] )
{
	return true;
}

int stringLength(char s[])
{
	int result = 0;

	while(s[result] != '\0')
	{
		result++;
	}

	return result;
}

void stringCopy(char destination[], char source[] )
{
	int i = 0;
	while(source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

//void displayStringBackward(char s[])
//{
//	int i = stringLength(s) - 1;
//	while(i >= 0)
//	{
//		cout << s[i];
//		i--;
//	}
//}

void displayStringBackward(char s[])
{
	char* p = s + stringLength(s);
	while(p >= s)
	{
		cout << *p;
		p--;
	}
}

void reverse(char s[])
{
	int size = stringLength(s);
	for(int i = 0; i < size/2; i++)
	{
		char temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
	}
}

//CSV
void displayWordsFromCSV(char s[])
{
	char word[100];
	int wordIndex = 0;
	for(int i = 0; i < strlen(s);i++)
	{
		//abc,123,xyz,prlkasjdf,Stuff, Hi
		//abc\0
		if(s[i] == ',' )
		{
			word[wordIndex] = '\0';
			cout << word << endl;
			wordIndex = 0;
		}
		else
		{
			word[wordIndex] = s[i];
			wordIndex++;
		}

		if(i == strlen(s)-1)
		{
			word[wordIndex] = '\0';
			cout << word << endl;
		}

	}
}

void main()
{
	//displayStringBackward("This is the day the Lord has made.");
	//string parsing
	char s[100];
	cin.getline(s,100);
	reverse(s);
	cout << s << endl;

	char s2[100];
	strcpy(s2,s);
	cout << s2 << endl;

	displayWordsFromCSV("abc,123,xyz,prlkasjdf,Stuff, Hi");
}