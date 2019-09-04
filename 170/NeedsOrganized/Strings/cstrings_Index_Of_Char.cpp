//this program displays the index of every instance of a char in a string

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

const int BAD_INDEX = -1;

void printIndexOfChar( const char s[], char c )
{
	int result = BAD_INDEX;

	for(int i = 0; s[i] != '\0' && result == BAD_INDEX; i++)
	{
		if(s[i] == c && i != BAD_INDEX)
		{
			cout << s << " contains a(n) " << c 
			 << " at index " << i << endl;
		}
	};
}

int main()
{
	char s[100];
	char c;

	cout << "Enter a word: ";
	cin >> s;//remember, cin stops at any whitespace,
	         //so only on word will be taken
	cin.ignore();

	cout << "Character: ";
	cin >> c;
	cin.ignore();

	printIndexOfChar(s,c);
	
	cin.get();
	return 0;

}






