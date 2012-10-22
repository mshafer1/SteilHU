#include<iostream>
#include<fstream>

using namespace std;

char getCommand()
{
	char result;
	cout << "(A)dd entry\n";
	cout << "(S)earch\n";
	cout << "(D)isplay all\n";
	cout << "(R)emove\n>";
	cout << "(Q)uit\n>";
	cin >> result;
	cin.ignore(cin.rdbuf()->in_avail() + 1);
	return toupper(result);
}

void add()
{
	char name[100];
	char phoneNumber[100];

	cout << "Name? ";
	cin.getline(name,100);

	cout << "Phone Number? ";
	cin.getline(phoneNumber,100);
	
	ofstream fout;
	fout.open("contacts.txt",ios::app);

	fout << name << endl;
	fout << phoneNumber << endl;
	fout.close();

}

void search()
{
	char searchName[100];
	char name[100];
	char phoneNumber[100];

	cout << "Who? ";
	cin.getline(searchName,100);
	
	ifstream fin("contacts.txt");

	while(!fin.eof())
	{
		fin.getline(name,100);
		fin.getline(phoneNumber,100);
		
		char* p = strstr(name, searchName);
		
		if(p != NULL)
		{
			cout << name << "'s phone number is ";
			cout << phoneNumber << endl;
		}
	}
	fin.close();
}

void remove()
{
	ifstream fin;
	ofstream fout;
	fin.open("contacts.txt");
	fout.open("contacts_temp.txt");

	char searchName[100];
	char name[100];
	char phoneNumber[100];

	cout << "Delete Who? ";
	cin.getline(searchName,100);

	while(!fin.eof())
	{
		fin.getline(name,100);
		fin.getline(phoneNumber,100);
		fout << name << endl;
		fout << phoneNumber << endl;
	}

	fin.close();
	fout.close();

	fin.open("contacts_temp.txt");
	fout.open("contacts.txt");

	while(!fin.eof())
	{
		fin.getline(name,100);
		fin.getline(phoneNumber,100);
		if(strcmp(name, searchName) != 0 )
		{
			fout << name << endl;
			fout << phoneNumber << endl;
		}
	}

	fin.close();
	fout.close();


}


void displayAll()
{
	ifstream fin;
	fin.open("contacts.txt");

	char name[100];
	char phoneNumber[100];
	while(!fin.eof())
	{
		fin.getline(name,100);
		fin.getline(phoneNumber,100);
		cout << name << endl;
		cout << phoneNumber << endl << endl;
	}

	fin.close();
}

int main()
{
	char userCommand = getCommand();
	
	while(userCommand != 'Q')
	{
		system("clear");
		switch(userCommand)
		{
			case 'A':
				add();
				break;
			case 'S':
				search();
				break;
			case 'D':
				displayAll();
				break;
			case 'R':
				remove();
				break;
		}

		userCommand = getCommand();
	}


	return 0;
}








