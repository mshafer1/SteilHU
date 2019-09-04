#include<iostream>
using namespace std;

void main()
{
	char original[100];
	char result[100] = "";
	char temp[100] = "";

	cin.getline(original, 100);

	char* token = strtok(original," ");

	while(token != NULL)
	{
		strcpy( temp, " ");
		strcat(temp, token);
		strcat(temp, result);
		strcpy(result, temp);

		token = strtok(NULL," ");
	}
	strcpy(result, result + 1);

	cout << result << endl;
}


