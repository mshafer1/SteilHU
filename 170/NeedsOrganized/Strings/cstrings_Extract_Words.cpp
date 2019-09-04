//this program seperates words within a c-style string

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

	int wordIndex = 0;

	for(unsigned int phraseIndex = 0; phraseIndex <= strlen(phrase); phraseIndex++)
	{	//loop through all of the characters in the phrase
		
		word[wordIndex] = phrase[phraseIndex];
		    //copy the next character from the phrase into the next available spot in the word

		if(word[wordIndex] == ' ' || word[wordIndex] == '\0')
		{   //when the character that was just copied from the phrase was a 
		    //  space or the null terminator the end of the word was found
			
			word[wordIndex] = '\0';
                //terminate the word with the null character
			
			cout << word << endl;
                //use the word
            
			wordIndex = 0;
			    //move the wordIndex back to 0 to get ready for the next word
		}
		else
		{
			wordIndex++;
			    //only increment the wordIndex when there are still characters 
			    //  put put in the current word
		}
	}
    cin.get();
    return 0;
}
