#include<iostream>
#include<string>

using namespace std;

void InputOutput();
void InputOutput2();
void Assignment();
void Concatenation();
void Contains();

void main()
{
//	InputOutput();
	InputOutput2();
//	Assignment();
//	Concatenation();
//	Contains();
}

void InputOutput()
{
	cout << endl << "InputOutput example" << endl;

	string S;
	
	//get console input until first white space
	cin >> S;

	//place entire contents of S onto console 
	cout << S << endl;
}

void InputOutput2()
{
	cout << endl << "InputOutput2 example" << endl;

	string S;
	
	//get console input until first white space
	getline(cin, S,char(10));

	//place entire contents of S onto console 
	cout << S << endl;
}

void Assignment()
{
	cout << endl << "Assignment example" << endl;
	//string can be initialize at declaration
	string S = "John";

	cout << S << endl;

	//string can contain white space
	S = "John Smith\nSaid\tHi";
	cout << S << endl;
}

void Concatenation()
{
	cout << endl << "Concatenation example" << endl;

	string S1 = "This is";
	string S2 = "fun";

	//out puts the combination of the two but does not change ether
	cout << S1 + " Boring" << endl;

	S1 = S1 + " " + S2;

	cout << S1 << endl;
}

void Contains()
{
	cout << endl << "Contains example" << endl;

	string S1 = "Please excuse my dear aunt sally";

	if (S1.find("dear") != string::npos)
	{
		cout << "Found the dear" << endl;
	}
	else
	{
		cout << "No dear in that string" << endl;
	}

	string S2 = "Ear";

	// it is case sensitive
	// you can search for another string
	if (S1.find(S2) != string::npos)
	{
		cout << "Found the ear" << endl;
	}
	else
	{
		cout << "No ear in that string" << endl;
	}
}
