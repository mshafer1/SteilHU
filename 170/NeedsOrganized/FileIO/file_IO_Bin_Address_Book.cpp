//this program allows the user to create and edit an address book.
//ifstream, ofstream, and fstream are used

#include<iostream>
#include<string>
#include<fstream>

using std::ios;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::string;

const int SEARCH = 1;
const int ADD = 2;
const int VIEW_BOOK = 3;
const int EDIT = 4;
const int EXIT = 0;
const int ENTRY_NOT_FOUND = -1;
const char FILE_NAME[] = "Address Book.dat";

void Add();
void Search();
void GetUserSelection(int& UserSelection);
void ShowMenu();
void ViewBook();
void EditBook();

int main()
{
	int UserSelection;

	do
	{
		GetUserSelection(UserSelection);
	
		switch (UserSelection)
		{
			case SEARCH:
				Search();
				break;
			case ADD:
				Add();
				break;
			case VIEW_BOOK:
				ViewBook();
				break;
			case EDIT:
				EditBook();
				break;
		};

	}
	while(UserSelection != EXIT);
	return 0;
}


int EntryIndex(string SearchName)
{
	int Result = ENTRY_NOT_FOUND;

	char Name[50];
	char Address[200];
	char PhoneNumber[25];
	int Age;

	ifstream fin(FILE_NAME);

	int Entry = 0;

	if(fin)
	{
		while(!fin.eof())
		{

			fin.read(Name,sizeof(Name));
			fin.read(Address,200);
			fin.read(PhoneNumber,25);
			fin.read((char*)&Age,sizeof(Age));
			
			if (!fin.eof() && SearchName == Name )
			{
				Result = Entry;
			}
			Entry++;
		}
	}
	else
	{
		cout << "Address Book not Available" << endl;
	}
	
	fin.close();
	return Result;
}
void Search()
{
	char Name[50];
	char Address[200];
	char PhoneNumber[25];
	string SearchName;
	int Age;

	cout << "Search For Name? ";
	getline(cin,SearchName);

	int Index = EntryIndex(SearchName);

	if (Index != ENTRY_NOT_FOUND)
	{
		ifstream fin;

		fin.open(FILE_NAME);

		fin.seekg(Index * 279); 

		fin.read(Name,sizeof(Name));
		fin.read(Address,200);
		fin.read(PhoneNumber,25);
		fin.read((char*)&Age,sizeof(Age));
		
		cout << Name << endl;
		cout << Address << endl;
		cout << PhoneNumber << endl;
		cout << Age << endl << endl;

		fin.close();
	}
}

//void SomeFunction(char S[])
//{
//	sizeof(S);
//}

void Add()
{
	char Name[50] = {'\0'};
	char Address[200] = {'\0'};
	char PhoneNumber[25] = {'\0'};
	int Age = 0;

	cin.get(); //trash the previous character return
	cout << "Name? ";
	cin.getline(Name,50);

	cout << "Address? ";
	cin.getline(Address,200);

	cout << "Phone Number? ";
	cin.getline(PhoneNumber,25);

	cout << "Age?";
	cin >> Age;
	cout << endl;

	ofstream fout;

	//ios::trunc
	fout.open(FILE_NAME,ios::app | ios::binary); // open the file for appending
	//write expects (const char*, int)
	fout.write(Name,sizeof(Name));
	fout.write(Address,200);
	fout.write(PhoneNumber,25);
	fout.write((char*)&Age,sizeof(Age));

	fout.close();
}

void ViewBook()
{
	ifstream fin;

	fin.open(FILE_NAME);

	char Name[50];
	char Address[200];
	char PhoneNumber[25];
	int Age;
	
	if(fin)
	{
		while(!fin.eof())
		{
			fin.read(Name,sizeof(Name));
			fin.read(Address,200);
			fin.read(PhoneNumber,25);
			fin.read((char*)&Age,sizeof(Age));
			if (!fin.eof())
			{
				if(Name[0] != '\0') 
				{
					cout << Name << endl;
				}
				if(Address[0] != '\0') 
				{
					cout << Address << endl;
				}
				if(PhoneNumber[0] != '\0')
				{
					cout << PhoneNumber << endl;
				}
				if(Age)
				{
					cout << Age << endl << endl;
				}
			}
		}
	}
	else
	{
		cout << "Address Book not Available" << endl;
	}

	fin.close();
}

void GetUserSelection(int& UserSelection)
{
	do
	{
		ShowMenu();
		cout << ">";
		cin >> UserSelection;
	}
	while(UserSelection < 0 || UserSelection > 4);

	//trash everything left in the input buffer
	cin.ignore(cin.rdbuf()->in_avail());
	//cin.get();
}

void ShowMenu()
{
	cout << "(1) Search" << endl;
	cout << "(2) Add" << endl;
	cout << "(3) View" << endl;
	cout << "(4) Edit" << endl;
	cout << "(0) Exit" << endl;
}








void EditBook()
{
	char Name[50];
	char Address[200];
	char PhoneNumber[25];
	string SearchName;
	int Age;

	cout << "Search For Name? ";
	getline(cin,SearchName);

	int Index = EntryIndex(SearchName);

	if (Index != ENTRY_NOT_FOUND)
	{
		fstream BookFile;

		BookFile.open(FILE_NAME, ios::in | ios::out);

		cout << BookFile.tellp() << endl;
		BookFile.seekg(Index * 279); 
		cout << BookFile.tellp() << endl;

		BookFile.read(Name,sizeof(Name));
		BookFile.read(Address,200);
		BookFile.read(PhoneNumber,25);
		BookFile.read((char*)&Age,sizeof(Age));
		
		cout << BookFile.tellp() << endl;

		cout << Name << endl;
		cout << Address << endl;
		cout << PhoneNumber << endl;
		cout << Age << endl << endl;

		cout << "Name? ";
		cin.getline(Name,50);

		cout << "Address? ";
		cin.getline(Address,200);

		cout << "Phone Number? ";
		cin.getline(PhoneNumber,25);

		cout << "Age?";
		cin >> Age;
		cin.get(); //trash end of line char

		BookFile.seekp(Index * 279); 

		//write expects (const char*, int)
		BookFile.write(Name,sizeof(Name));
		BookFile.write(Address,200);
		BookFile.write(PhoneNumber,25);
		BookFile.write((char*)&Age,sizeof(Age));

		BookFile.close();
	}
}


















