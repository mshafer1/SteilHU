#include<iostream>
using namespace std;

// write a funtion named displayBackward
//it should take a c-style string as an argument and then
//display one character at a time from the last to the first

//be sure to call the displayBackwardFunction from main to 
//make sure it works

int stringLength(char s[])
{
	int result = 0;

	while(s[result] != '\0')
	{
		result++;
	}

	return result;
}

void main()
{
	//c-style string an array of characters with a null terminator
	// null terminator is the char with the ascii value 0
	int A[10] = {0};
	cout << A << endl;

	char s[5] = {'D','a','n','a','\0'};
	cout << s << endl;
	cout << s + 1 << endl;
	cout << *(s + 1) << endl;
	cout << s[1] << endl;

	char s2[] = "Dana";
	cout << "example:" <<  s2 << endl;
	// "a" vs 'a'
	
	cout << "Length of " << s2 << "=" << stringLength(s2) << endl;

	for(char c = 0; c < 254; c++)
	{
		//type cast
		cout << c  << "=" << (int)c<<  endl;
	}


}



