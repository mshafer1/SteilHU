#include <iostream>
using namespace std;

bool isSameString (char s1[], char s2[]);

char upper(char c)
{
	char result = c;

	if(c >= 'a' && c <= 'z')
	{
		const int UPPER_LOWER_CASE_DELTA = 32;
		c = c - UPPER_LOWER_CASE_DELTA;
	}

	return c;
}

char lower(char c)
{
	char result = c;

	if(c >= 'A' && c <= 'Z')
	{
		const int UPPER_LOWER_CASE_DELTA = 32;
		c = c + UPPER_LOWER_CASE_DELTA;
	}

	return c;
}

bool isSameString (char s1[], char s2[])
{
    bool result = true;
    int i = 0;
	if(strlen(s1) != strlen(s2))
	{
		result = false;
	}
	else
	{
		while (s1[i] != '\0')
		{
			char c1 = upper(s1[i]);
			char c2 = upper(s2[i]);
			if (c1 != c2)
			{
				result = false;
			}
			i++;
		}
	}
    return result;
}

void appendStrings(char destination[], char source[])
{
	int destinationLength = strlen(destination);
	int sourceLength = strlen(source);

	for(int i = 0; i <= sourceLength; i++)
	{
		destination[destinationLength + i] = source[i];
	}

}

void main ()
{
	cout << (int)'a'  << (int)'A' << endl;
    //cout << "apple" << endl;
    //cout << "orange" << endl << endl;

	char s1[100] = "";
	char s2[100] = "";
	cin >> s1;
	cin >> s2;

	if(strcmp(s1,s2) == 0)
	{
		cout << "Same" << endl;
	}
	else if(strcmp(s1,s2) > 0)
	{
		cout << s1 << " is greater than " << s2 << endl;
	}
	else
	{
		cout << s2 << " is greater than " << s1 << endl;
	}

	//appendStrings(s1,s2);
	//cout << s1 << endl;

    /*bool result = isSameString (s1, s2);

    if (result == true)
    {
        cout << "Same." << endl << endl;
    }
    else if (result == false)
    {
        cout << "Different." << endl << endl;
    }

    system("Pause");*/
}