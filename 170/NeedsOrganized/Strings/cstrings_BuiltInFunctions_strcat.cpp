//this program uses strcat() to concatenate, or append, one string to another

	// strcat(char a[], char b[]) strcat takes c-style string b and adds it 
	//		to the end of c-style string a. The function returns a.
	
	// The "cat" in strcat(): think "conCATenate"


#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	char s1[250] = "I can't stop laughing! "; // [250] because we're going to need more space
	char s2[] = "ha"; //dont forget that "ha" is the same as {'H', 'a','\0'}
	
	
	for (int i = 0; i < 100; i++)
	{
		strcat(s1, s2);
	}
	
	cout << s1;

	cin.get();
	return 0;
}