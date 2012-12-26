//this program is in included in the rough folder because
//it is not very polished and it accomplishes similar things
//as addressBook.cpp

#include<iostream>
#include<fstream>
#include<string>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::cout;
using std::cin;
using std::ios;
using std::endl;

struct CHeight
{
	int Feet;
	int Inches;
};

const int MAX_NAME_LENGTH = 30;

struct CSuperHero
{
	char Name[60];
	CHeight Height;
	int Age;	
};

const char* SUPER_HERO_FILE_NAME = "SuperHero.dat"; 

void GetSuperHeroFromUser(CSuperHero& SuperHero);
void ShowSuperHero(CSuperHero& SuperHero);
void ShowSuperHeros();
void AppendSuperHeroToFile(CSuperHero SuperHero);
void ReadSuperHeroFromFile();
void UpdateSuperHero();
void ShowMenu();
void PreformUsersCommand(char MenuSelection);

int main()
{
	char MenuSelection;

	ShowMenu();

	cin >> MenuSelection;
	MenuSelection = toupper(MenuSelection);
	cin.ignore(cin.rdbuf()->in_avail(),'\n');

	while (MenuSelection != 'Q')
	{
		PreformUsersCommand(MenuSelection);
		ShowMenu();

		cin >> MenuSelection;
		MenuSelection = toupper(MenuSelection);
		cin.ignore(cin.rdbuf()->in_avail(),'\n');
	}
	return 0;
}

void GetSuperHeroFromUser(CSuperHero& SuperHero)
{
	cout << "Name: ";
	cin.getline(SuperHero.Name, MAX_NAME_LENGTH);
	cin.ignore(cin.rdbuf()->in_avail(),'\n');

	cout << "Height: "<< endl;
	cout <<	"       Feet: ";
	cin >> SuperHero.Height.Feet;
	cin.ignore(cin.rdbuf()->in_avail(),'\n');

	cout << "       Inches: ";
	cin >> SuperHero.Height.Inches;
	cin.ignore(cin.rdbuf()->in_avail(),'\n');

	cout << "Age: ";
	cin >> SuperHero.Age;
	cin.ignore(cin.rdbuf()->in_avail(),'\n');

	cout << endl;
}

void ShowSuperHero(CSuperHero& SuperHero)
{
	cout << SuperHero.Name << " is " << endl;
	cout << SuperHero.Height.Feet << "' and " 
		 << SuperHero.Height.Inches << "\" tall" << endl;
	cout << "and is " << SuperHero.Age << " years old." << endl;
}

void ShowSuperHeros()
{
	ifstream SuperHeroFile;
	CSuperHero SuperHero;

	SuperHeroFile.open(SUPER_HERO_FILE_NAME, ios::binary);

	while(!SuperHeroFile.eof())
	{
		SuperHeroFile.read((char*) &SuperHero,sizeof(CSuperHero));
		ShowSuperHero(SuperHero); 
	}

	SuperHeroFile.close();
}

void AppendSuperHeroToFile(CSuperHero SuperHero)
{
	ofstream SuperHeroFile;

	SuperHeroFile.open(SUPER_HERO_FILE_NAME, ios::app|ios::binary);

	SuperHeroFile.write((const char*)&SuperHero, sizeof(CSuperHero));

	SuperHeroFile.close();
}

void ReadSuperHeroFromFile()
{
	ifstream SuperHeroFile;
	int SupperHeroIndex;
	CSuperHero SuperHero;

	cout << "Please enter the number of the super hero to view: ";
	cin >> SupperHeroIndex;
	cin.ignore(cin.rdbuf()->in_avail(),'\n');

	SuperHeroFile.open(SUPER_HERO_FILE_NAME, ios::binary);

	SuperHeroFile.seekg(sizeof(CSuperHero) * SupperHeroIndex);
	SuperHeroFile.read((char*)&SuperHero,sizeof(CSuperHero));

	ShowSuperHero(SuperHero);

	SuperHeroFile.close();
}

void UpdateSuperHero()
{
	fstream SuperHeroFile;
	int SupperHeroIndex;
	CSuperHero SuperHero;

	cout << "Please enter the number of the super hero to Update: ";
	cin >> SupperHeroIndex;
	cin.ignore(cin.rdbuf()->in_avail(),'\n');
	

	SuperHeroFile.open(SUPER_HERO_FILE_NAME, ios::in | ios::out | ios::binary );

	SuperHeroFile.seekg(sizeof(CSuperHero) * SupperHeroIndex);
	SuperHeroFile.read((char*)&SuperHero,sizeof(CSuperHero));

	ShowSuperHero(SuperHero);
	GetSuperHeroFromUser(SuperHero);

	SuperHeroFile.seekp(sizeof(CSuperHero) * SupperHeroIndex);
	SuperHeroFile.write((const char*)&SuperHero, sizeof(CSuperHero));

	SuperHeroFile.close();
}

void ShowMenu()
{
	cout << "(A) Add super hero " << endl;
	cout << "(S) Show all super heros " << endl;
	cout << "(F) Read super hero " << endl;
	cout << "(U) Update super hero " << endl;
	cout << "(Q) Quit" << endl;
}

void PreformUsersCommand(char MenuSelection)
{
	CSuperHero SuperHero;

	switch (MenuSelection)
	{
		case 'A':
			GetSuperHeroFromUser(SuperHero);
			AppendSuperHeroToFile(SuperHero);
			break;
		case 'S':
			ShowSuperHeros();
			break;
		case 'F':
			ReadSuperHeroFromFile();
			break;
		case 'U':
			UpdateSuperHero();
		break;		default:
			cout << "Sorry, menu selection not recognized." << endl;
		
	}
}

