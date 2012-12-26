//this program is to illustrates how to extract a word at time from a c-style string

#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

const int SIZE = 101;

int main()
{
	char phrase[SIZE] = "";
	char word[SIZE]= "";

	cout << "Enter a phrase> ";
	cin.getline(phrase, SIZE);

	//decalare two pointers to characters, the prefix p indicates that the variable is a pointer
	//one to hold the address of the next space
	//one to hole the address of the begingin of the current word
	char* pSpace = strchr(phrase, ' ');
	char* pWordStart = phrase;

	//while there is another space in the phrase
	while(pSpace != NULL)
	{
		//the number of characters in the current word can be found by substracting 
		//the address of the begingin of the word from the address of the space after the word
		int wordLength = int(pSpace - pWordStart);

		//copy the characters from pWordStart till the end of the phrase into the word
		strcpy_s(word, pWordStart);
		
		//terminate the word at the index where the space was found
		word[wordLength] = '\0';

		//do something usefull with the word
		cout << word << endl;

		//assume that the next word starts just after the space that was found
		pWordStart = pSpace + 1;

		//look for another space starting just after the point where the last space was found
		pSpace = strchr(pSpace + 1, ' ');
	}

	//after all of he spaces are found tere is still one word left in the phrase
	strcpy_s(word, pWordStart);
	cout << word << endl;
    
    cin.get();
    return 0;
}
