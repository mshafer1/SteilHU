#include<iostream>
#include<time.h>
#include<string>

using namespace std; 

bool IsVowel(char c)
{
	bool Result = false;
	switch (toupper(c))
	{
		case 'A': case 'E': case 'I': case 'O': case 'U': 
			Result = true;
			break;
	}
	return Result;
}

bool IsConsonant(char c)
{
	bool Result = false;

	c = toupper(c);
	if(c >= 'A' && c <= 'Z' && !IsVowel(c))
	{
		Result = true;
	}

	return Result;
}

//assume the word has no leading whitespace
int LeadingConsonants(char word[])
{
	int Result = 0;
	for(Result = 0; IsConsonant(word[Result]); Result++); 
	return Result;
}
//"This is the day the Lord has made"
char* Tokenize(char* p,char Delimiter)
{
	static char* Result = NULL;
	static char* d = NULL;

	if(p != NULL)
	{
		Result = p;
		d = strchr(Result,Delimiter);
	}
	else //at least second time searching this string
	{
		if(d != NULL)  //we found a delimiter last time
		{
			Result = Result + strlen(Result) + 1;
			d = strchr(Result,Delimiter);
		}
		else //we must be done searching
		{
			Result = NULL;
		}
	}

	if(d != NULL)
	{
		*d = '\0';
	}

	return Result;
}


void main()
{
	char A[100];
	char B[100] = "This is the\tday\nthe Lord has made ";
	//cin.getline(A,100);

	//string token
	//delimiter - char used to seperate 
	char* p = strtok(B," \t\n");

	while(p != NULL)
	{
		cout << p << endl;
        p = strtok(NULL," \t\n");
	}

	//char* pCurrentWord = A;
	//char* pSpace = strchr(pCurrentWord,' ');
	////first word begins at A stops at pSpace -1
	//while(pSpace != NULL)
	//{
	//	*pSpace = '\0';
	//	cout << pCurrentWord << endl;
	//	pCurrentWord = pSpace + 1;
	//	pSpace = strchr(pSpace + 1,' ');
	//}
	//cout << pCurrentWord << endl;
}
