#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int SEARCH = 1;
const int ADD = 2;
const int VIEW_BOOK = 3;
const int EDIT = 4;
const int EXIT = 0;

const int ENTRY_NOT_FOUND = -1;

const char FILE_NAME[] = "Address Book.dat";

struct CEntry
{
	char Name[50];
	char Address[200];
	char PhoneNumber[25];
	int Age;
};

void Add();
void Search();
void GetUserSelection(int& UserSelection);
void ShowMenu();
void ViewBook();
void EditBook();

void GetEntry(CEntry& Entry)
{
	cout << "Name? ";
	cin.getline(Entry.Name,50);

	cout << "Address? ";
	cin.getline(Entry.Address,200);

	cout << "Phone Number? ";
	cin.getline(Entry.PhoneNumber,25);

	cout << "Age?";
	cin >> Entry.Age;
	cin.get(); //trash end of line char
}

void DisplayEntry(const CEntry& Entry)
{
	cout << Entry.Name << endl;
	cout << Entry.Address << endl;
	cout << Entry.PhoneNumber << endl;
	cout << Entry.Age << endl << endl;
}

void main()
{
	cout << ios::app << endl;
	cout << ios::in << endl;
	cout << (ios::in | ios::app) << endl;

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
}


int EntryIndex(string SearchName)
{
	int Result = ENTRY_NOT_FOUND;

	ifstream fin(FILE_NAME);

	CEntry Entry;

	int EntryIndex = 0;

	if(fin)
	{
		while(!fin.eof())
		{
			fin.read((char*)&Entry, sizeof(CEntry));
			
			if (!fin.eof() && SearchName == Entry.Name )
			{
				Result = EntryIndex;
			}
			EntryIndex++;
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
	string SearchName;
		
	CEntry Entry;

	cout << "Search For Name? ";
	getline(cin,SearchName);

	int Index = EntryIndex(SearchName);

	if (Index != ENTRY_NOT_FOUND)
	{
		ifstream fin;

		fin.open(FILE_NAME);
		fin.seekg(Index * sizeof(CEntry)); 
		fin.read((char*)&Entry,sizeof(CEntry));

		DisplayEntry(Entry);

		fin.close();
	}
}

void Add()
{
	CEntry Entry;
	GetEntry(Entry);

	ofstream fout(FILE_NAME,ios::app | ios::binary); // open the file for appending

	//write expects (const char*, int)
	fout.write((char*)&Entry,sizeof(CEntry));

	fout.close();
}

void ViewBook()
{
	ifstream fin;

	fin.open(FILE_NAME);

	if(fin)
	{
		CEntry Entry;

		while(!fin.eof())
		{
			fin.read((char*)&Entry,sizeof(CEntry));

			if (!fin.eof())
			{
				DisplayEntry(Entry);
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
	string SearchName;
	
	CEntry Entry;

	cout << "Search For Name? ";
	getline(cin,SearchName);

	int Index = EntryIndex(SearchName);

	if (Index != ENTRY_NOT_FOUND)
	{
		fstream BookFile (FILE_NAME, ios::in | ios::out);

		BookFile.seekg(Index * sizeof(CEntry)); 
		BookFile.read((char*)&Entry,sizeof(CEntry));

		DisplayEntry(Entry);
		GetEntry(Entry);

		BookFile.seekp(Index * sizeof(CEntry)); 

		//write expects (const char*, int)
		BookFile.write((char*)&Entry,sizeof(CEntry));

		BookFile.close();
	}
}