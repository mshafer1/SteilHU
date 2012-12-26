#include<iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_PHRASE_LENGTH = 1000;

void ReversePhrase(char Phrase[])
{
	char Result[MAX_PHRASE_LENGTH] = "";
	char Word[MAX_PHRASE_LENGTH] = "";

	char* AddressOfSpace = strchr(Phrase,' ');

	//While a space was found 
	while(AddressOfSpace != NULL)
	{
		//Copy the first word in Prase to Word
		int CharactersToCopy = (int)(AddressOfSpace - Phrase);
		strncpy(Word,Phrase, CharactersToCopy);
		Word[CharactersToCopy] = '\0';
		
		//Add the word to the begining of the Result
		strcat(Word, " ");
		strcat(Word, Result);
		strcpy(Result, Word);

		//If there is another word remove the first word skipping the space
		if(Phrase[CharactersToCopy] != '\0')
		{
			strcpy(Phrase, Phrase + CharactersToCopy + 1); 
		}

		//find the next space
		AddressOfSpace = strchr(Phrase,' ');
	}

	strcat(Phrase," ");
	strcat(Phrase, Result);
	strcpy(Result, Phrase);
}

int main()
{
	char Phrase[MAX_PHRASE_LENGTH];

	cin.getline(Phrase,MAX_PHRASE_LENGTH);

	ReversePhrase(Phrase);

	cout << Phrase << endl;

	cin.get();
	return 0;

}
