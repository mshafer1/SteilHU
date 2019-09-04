#include<iostream>
using namespace std;
 
void TranslateToPigLatin(char Phrase[]);
const int MAX_PHRASE_LENGTH = 1000;
const int MAX_WORD_LENGTH = 100;
 
void main()
{
      char Phrase[MAX_PHRASE_LENGTH];
     
      cout << "Please enter a phrase to be translated to Pig Latin:" << endl;
      cin.getline(Phrase, MAX_PHRASE_LENGTH);
 
      TranslateToPigLatin(Phrase);
 
      cout << Phrase << endl;
}

bool isVowel(char c)
{
	bool result = false;
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
		c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		result = true;
	}
	return result;
}

int CountLeadingConsonants(char Word[])
{
	int result = 0;

	while(!isVowel(Word[result]) && Word[result] != '\0')
	{
		result ++;
	}

	return result;
}

void TranslateWordToPigLatin(char Word[])
{
	char result[MAX_WORD_LENGTH];
	if(isVowel(Word[0]))
	{
		strcat(Word,"yay");
	}
	else
	{
		int consonantCount = CountLeadingConsonants(Word);
		strcpy(result, Word + consonantCount);
		strcat(result,Word);
		result[strlen(Word)] = '\0';		
		strcat(result,"ay");
		strcpy(Word,result);
	}
}

void TranslateToPigLatin(char Phrase[])
{
	char answer[MAX_PHRASE_LENGTH] = "";
	char word[MAX_WORD_LENGTH];
	int wordIndex = 0;
	for(int i = 0; i <= strlen(Phrase);i++)
	{
		if(Phrase[i] != ' ' && Phrase[i] != '\0')
		{
			word[wordIndex] = Phrase[i];
			wordIndex++;
		}
		else
		{
			//reached the end of a word in the Phrase
			word[wordIndex] = '\0';
			wordIndex = 0;
			TranslateWordToPigLatin(word);
			strcat(answer,word);
			strcat(answer," ");
		}

	}


	strcpy(Phrase,answer);
}