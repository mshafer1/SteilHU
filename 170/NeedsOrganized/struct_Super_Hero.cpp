#include<iostream>
#include<string>

using namespace std;

struct Height_Type
{
	int Feet;
	int Inches;
};

struct SuperHero_Type
{
	string Name;
	int Age;
	string SuperPower;
	string Alias;
	float Weight;
	Height_Type Height; 
};

void GetHeight(Height_Type& Height)
{
	cout << "Height (Feet Inches): ";
	cin >> Height.Feet;
	cin >> Height.Inches;
}
void GetSuperHero(SuperHero_Type& SuperHero)
{
	cout << "Name: ";
	getline(cin, SuperHero.Name);

	cout << "Age: ";
	cin >> SuperHero.Age;
	cin.get(); //throws away end of line char

	cout << "Alias: ";
	getline(cin,SuperHero.Alias);

	cout << "Super Power: ";
	getline(cin, SuperHero.SuperPower);

	cout << "Weight: ";
	cin >> SuperHero.Weight;

	GetHeight(SuperHero.Height);
}



void DisplayHeight(const Height_Type& Height)
{
	cout << "Height: ";
	cout << Height.Feet << " ft. ";
	cout << Height.Inches << " in. " << endl;
}

void DisplaySuperHero(const SuperHero_Type& SuperHero)
{
	cout << "Name: " << SuperHero.Name << endl;
	cout << "Age: " << SuperHero.Age << endl;
	cout << "Alias: " << SuperHero.Alias << endl;
	cout << "Super Power: " << SuperHero.SuperPower << endl;
	cout << "Weight: " << SuperHero.Weight << endl;
	DisplayHeight(SuperHero.Height);
}

void main()
{
	//int x;
	//string s;

	//cin >> x;
	//
	//char c = cin.get();
	////getline(cin,s);
	//getline(cin,s);

	//cout << x << endl;
	//cout << s << endl;

	SuperHero_Type SuperHero;

	GetSuperHero(SuperHero);
	DisplaySuperHero(SuperHero);


	


}