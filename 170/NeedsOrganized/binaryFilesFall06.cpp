#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	char name[25];
	int age;

	//cin.getline(name,25);
	//cin >> age;

	//ofstream fout;
	//fout.open("junk.out", ios::binary | ios::app);

	//fout.write( (char*) &age, 4);
	//fout.write( name, 25);

	//fout.close();

	ifstream fin;
	fin.open("junk.out", ios::binary );

	int index;
	cin >> index;

	fin.seekg(index * 29);

	fin.read((char*)&age, 4);
	fin.read(name,25);

	cout << age << endl;
	cout << name << endl;

	fin.close();

}

