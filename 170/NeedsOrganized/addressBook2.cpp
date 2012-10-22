#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int NAME_LENGTH = 50;
const int ADDRESS_LENGTH = 100;
const int PHONE_LENGTH = 15;
const int EMAIL_LENGTH = 50;

struct Contact
{
	char name[NAME_LENGTH];
	char address[ADDRESS_LENGTH];
	char phoneNumber[PHONE_LENGTH];
	char email[EMAIL_LENGTH];
};

void getContact(Contact& contact)
{
	cout << "Name? ";
	cin.getline(contact.name,NAME_LENGTH);
	cout << "Address? ";
	cin.getline(contact.address,ADDRESS_LENGTH);
	cout << "Phone Number? ";
	cin.getline(contact.phoneNumber,PHONE_LENGTH);
	cout << "Email? ";
	cin.getline(contact.email,EMAIL_LENGTH);
}

void displayContact(const Contact& contact)
{
	cout << "Name: ";
	cout << contact.name << endl;
	cout << "Address? ";
	cout << contact.address << endl;
	cout << "Phone Number? ";
	cout << contact.phoneNumber << endl;
	cout << "Email? ";
	cout << contact.email << endl;
}


void addContact(Contact*& contacts, int& totalContacts)
{
	Contact* newContacts = new Contact[totalContacts + 1];
	
	for(int i = 0; i < totalContacts; i++)
	{
		newContacts[i] = contacts[i];
	}

	delete[] contacts;
	contacts = newContacts;

	getContact( contacts[totalContacts]);
	totalContacts++;
}

void  readContacts(Contact*& contacts, int& totalContacts)
{
	ifstream fin("addresses.add",ios::binary);

	if(fin.fail())
	{
		//file did not exist
		contacts  = new Contact[10];
	}
	else
	{
		fin.read((char*)&totalContacts,4);
		contacts  = new Contact[totalContacts + 10];
		
		for(int i = 0; i < totalContacts; i++)
		{
			fin.read(contacts[i].name,NAME_LENGTH);
			fin.read(contacts[i].address,ADDRESS_LENGTH);
			fin.read(contacts[i].phoneNumber,PHONE_LENGTH);
			fin.read(contacts[i].email,EMAIL_LENGTH);
		}
	}

	fin.close();
}

void  writeContacts(Contact* contacts, int totalContacts)
{
	ofstream fout("addresses.add",ios::binary);

	fout.write((char*)&totalContacts,4);

	for(int i = 0; i < totalContacts; i++)
	{
		fout.write(contacts[i].name,NAME_LENGTH);
		fout.write(contacts[i].address,ADDRESS_LENGTH);
		fout.write(contacts[i].phoneNumber,PHONE_LENGTH);
		fout.write(contacts[i].email,EMAIL_LENGTH);
	}

	fout.close();
}


void main()
{
		Contact* contacts = NULL;
		int totalContacts = 0;

		readContacts(contacts, totalContacts);

		for(int i = 0; i < totalContacts; i++)
		{
			displayContact(contacts[i]);
		}

		addContact(contacts,totalContacts );

		writeContacts(contacts, totalContacts);
}











