#include<iostream>
#include<string>

using namespace std;

void strlenExample()
{
	char s[50];

	cout << "Enter word or phrase to get its lenght: ";
	cin.getline(s,50);
	cout << '"' << s <<  "\" is " << strlen(s) << " characters long" << endl;

	// \" for "
	// \\ for \
	// \n for end of line
	// \0 for null terminator
	// \a beep
}

void strcpyExample()
{
	char s1[50];
	char s2[50];

	cin >> s1;

	//s2 = s1;
	strcpy(s2,s1);

	cout << s2 << endl;
}
//copy the first n letters
void strncpyExample()
{
	char s1[10] = "bob";
	char s2[] = "abcdefg";

	strncpy(s1,s2,5);

	cout << s1 << endl;
}


//string compare
//returns 0 if they are the same
void strcmpExample()
{
	char s1[] = "apple";
	char s2[] = "Apple";

	if(strcmp(s1,s2) == 0)
	{
		cout << "They are the same" <<endl;
	}
	else if (strcmp(s1,s2) > 0)
	{
		cout << s1 << " is greater than " << s2 << endl; 
	}
	else if (strcmp(s1,s2) < 0)
	{
		cout << s1 << " is less than " << s2 << endl; 
	}
}

void stricmpExample()
{
	char s1[] = "apple";
	char s2[] = "Apple";

	if(stricmp(s1,s2) == 0)
	{
		cout << "They are the same" <<endl;
	}
	else if (stricmp(s1,s2) > 0)
	{
		cout << s1 << " is greater than " << s2 << endl; 
	}
	else if (stricmp(s1,s2) < 0)
	{
		cout << s1 << " is less than " << s2 << endl; 
	}
}

void strncmpExample()
{
	char s1[] = "App";
	char s2[] = "Apple";

	if(strncmp(s1,s2,4) == 0)
	{
		cout << "They are the same" <<endl;
	}
	else if (strncmp(s1,s2,4) > 0)
	{
		cout << s1 << " is greater than " << s2 << endl; 
	}
	else if (strncmp(s1,s2,4) < 0)
	{
		cout << s1 << " is less than " << s2 << endl; 
	}
}

void strnicmpExample()
{
	char s1[] = "appl";
	char s2[] = "Apple";

	if(strnicmp(s1,s2,4) == 0)
	{
		cout << "They are the same" <<endl;
	}
	else if (strncmp(s1,s2,4) > 0)
	{
		cout << s1 << " is greater than " << s2 << endl; 
	}
	else if (strncmp(s1,s2,4) < 0)
	{
		cout << s1 << " is less than " << s2 << endl; 
	}
}

void strchrExample()
{
	char Word[20];

	cin >> Word;

	while ( strchr(Word,'m')!= 0)
	{
		int index = int(strchr(Word,'m') - Word);
		Word[index] = 'n';
		cout << Word << endl;
		//cout << "it has one at " <<  strchr(Word,'m') << endl;
	}
}

void strstrExample()
{
	char Word[20];

	cin >> Word;

	if ( strstr(Word,"it")!= 0)
	{
		//int index = int(strstr(Word,"it") - Word);
		//Word[index] = 'n';
		cout << Word << "Contains an \"it\"."<< endl;
		//cout << "it has one at " <<  strchr(Word,'m') << endl;
	}
}

void UsefulExample()
{
	char Roster[5][40];

	strcpy(Roster[0], "Bob,123");
	strcpy(Roster[1], "Sue,124");
	strcpy(Roster[2], "Sam,125");
	strcpy(Roster[3], "Dana,126");
	strcpy(Roster[4], "Frank,127");
	//...

	char ID[20];
	char Name[20];
	int IndexOfComma;

	cout <<"ID? ";
	cin >>ID;


	for(int i = 0; i < 5; i++)
	{
		if (strstr(Roster[i],ID))
		{
			IndexOfComma = strchr(Roster[i],',') - Roster[i];
			//Roster[i][IndexOfComma] = '\0';
			strncpy(Name,Roster[i],IndexOfComma);
			Name[IndexOfComma] = '\0';
			
			cout << Name << endl;
		}
	}

}

void strcatExample()
{
	char Word[20];

	cin >> Word;

	strcat(Word,"ay");

	cout << Word << endl;
}

void strncatExample()
{
	char Word[20];

	cin >> Word;

	strncat(Word,"Smith", 2);

	cout << Word << endl;
}

void main()
{
	//strlenExample();
	//strcpyExample();
	//strncpyExample();
	//strcmpExample();
	//stricmpExample();
	//strncmpExample();
	//strnicmpExample();
	//strchrExample();
	//strstrExample();
	//strcatExample();
	strncatExample();
	//UsefulExample();
}
