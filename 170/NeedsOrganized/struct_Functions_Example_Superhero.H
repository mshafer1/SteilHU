#ifndef SUPER_HERO_H
#define SUPER_HERO_H

#include"Height.h"

const int MAX_NAME_LENGTH = 30;

struct CSuperHero
{
	char Name[60];
	CHeight Height;
	int Age;

	void Show()
	{
		cout << Name << " is " << endl;
		cout << Height.Feet << "' and " 
			 << Height.Inches << "\" tall" << endl;
		cout << "and is " << Age << " years old." << endl;
	}

	void Get()
	{
		cout << "Name: ";
		cin.getline(Name, MAX_NAME_LENGTH);
		cin.ignore(cin.rdbuf()->in_avail(),'\n');

		cout << "Height: "<< endl;
		cout <<	"       Feet: ";
		cin >> Height.Feet;
		cin.ignore(cin.rdbuf()->in_avail(),'\n');

		cout << "       Inches: ";
		cin >> Height.Inches;
		cin.ignore(cin.rdbuf()->in_avail(),'\n');

		cout << "Age: ";
		cin >> Age;
		cin.ignore(cin.rdbuf()->in_avail(),'\n');

		cout << endl;
	}

};

#endif