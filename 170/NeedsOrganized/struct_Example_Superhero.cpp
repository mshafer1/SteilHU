#include<iostream>
#include<string>

using namespace std;

struct SuperHeroType
{
	string Name;
	string Power;
	string Transportation;
	long Age;
	double Weight;
};

void Get(SuperHeroType& SuperHero);
void Show(SuperHeroType& SuperHero);

void main()
{
	SuperHeroType SuperHero;

	Get(SuperHero);
	Show(SuperHero);
}

void Get(SuperHeroType& SuperHero)
{
	cout << "Name? ";
	getline(cin,SuperHero.Name);
	cout << "Power? ";
	getline(cin,SuperHero.Power);
	cout << "Mode of Transportation? ";
	getline(cin,SuperHero.Transportation);
	cout << "Age? ";
	cin >> SuperHero.Age;
	cout << "Weight? ";
	cin >> SuperHero.Weight;
}

void Show(SuperHeroType& SuperHero)
{
	cout << "Name: " << SuperHero.Name << endl;
	cout << "Power: "<< SuperHero.Power << endl;
	cout << "Mode of Transportation: " << SuperHero.Transportation << endl;
	cout << "Age: " << SuperHero.Age << endl;
	cout << "Weight: " << SuperHero.Weight << endl;
}



