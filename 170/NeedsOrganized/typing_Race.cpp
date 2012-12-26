#include <iostream> 
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

void main()
{
	srand((unsigned int)time(0));

	time_t currentTime;	//time_t is a structure defined in ctime
	time_t startTime;
	//cout << asctime(localtime(&currentTime));

	char c = (char)(rand()%26 + 65);
	char InputCharacter;
	int CorrectResponses = 0;
	int Responses = 0;

	bool Started = false;

	do
	{
		system("cls");

		if (Started)
		{
			cout << 60 - (long)(currentTime - startTime) << endl;
		}
		else
		{
			cout << 60 << endl;
		}

		cout << c << endl;
		InputCharacter = getch();
		InputCharacter = toupper(InputCharacter);
		
		if (!Started)	
		{
			time(&startTime);
			Started = true;
		}

		time(&currentTime);

		if(InputCharacter == c && (currentTime - startTime) < 60)
		{
			c = (char)(rand()%26 + 65);
			CorrectResponses++;
		}

		if ((currentTime - startTime) < 60)
		{
			Responses++;
		}
	}
	while((currentTime - startTime) < 60);

	system("cls");
	cout << CorrectResponses << " out of " << Responses << " correct " << endl;

}
