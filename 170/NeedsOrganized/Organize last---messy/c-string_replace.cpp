#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

//this function will replace all occurances of key with text
void replace(char line[], char key[], char text[])
{
	char result[500] = "";
	bool keyFound = false;

	do
	{
		keyFound = false;
		for(unsigned int i = 0; i <= strlen(line) - 6 && !keyFound; i++)
		{
			if(strncmp(line + i, key, 6) == 0)
			{
				keyFound = true;
				// strncat() has been deprecated. it is now strncat_s()
				strncat_s(result,line, i);
				strcat_s(result,text);
				strcat_s(result, line + i + 6 );
			}
		}
		if( strlen(result) > 0 )
		{
			// strcpy() has been deprecated. it is now strcpy_s()
			strcpy_s(line, sizeof(result), result);
		}
		// strncat() has been deprecated. it is now strncat_s()
		strcpy_s(result, "");
	}
	while(keyFound);

}

int main()
{
	char line[500] = "This is a test %TIME% and %DATE% and %NAME% with another %TIME% and %DATE% and %NAME%.";

	cout << line << endl;

	replace(line, "%TIME%", "12:00 am");
	replace(line, "%DATE%", "11/15/2005");
	replace(line, "%NAME%", "Dana Steil");
	
	cout << line << endl;
	return 0;
}

