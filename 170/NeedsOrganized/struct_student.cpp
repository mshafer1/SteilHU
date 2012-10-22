# include<iostream>
# include<string>

using namespace std;

const int NAME_LENGTH = 50;
const int BIRTHDATE_LENGTH = 50;

struct CStudent
{
	char Name[NAME_LENGTH];
	int Age;
	char Birthdate[BIRTHDATE_LENGTH];
	bool Audit;
	float Weight;
};

void GetStudent( CStudent& Student )
{
	do
	{
		cout << "Name ? ";
		cin.getline( Student.Name, NAME_LENGTH );
	} while ( strlen(Student.Name) <= 0 );
	
	
	cout << "Age ? ";
	cin >> Student.Age;
	
	cin.get(); // to throw away the /n character
	
	cout << "Birth Date ? ";
	cin.getline( Student.Birthdate, BIRTHDATE_LENGTH );

	char Auditing;
	cout << "Auditing (Y/N)?";
	cin >> Auditing;

	if (Auditing == 'Y' || Auditing == 'y')
	{
		Student.Audit = true;
	}
	else
	{
		Student.Audit = false;
	}

	cout << "Weight ? ";
	cin >> Student.Weight;

	cin.get(); // to throw away the /n character
}

void DisplayStudent( CStudent Student)
{
	cout << "Name : " << Student.Name << endl;
	cout << "Age : " << Student.Age << endl;
	cout << "Birth Date : " << Student.Birthdate << endl;
	
	cout << "Auditing : ";

	if ( Student.Audit )
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << "Weight : " << Student.Weight << endl;


}

void main()
{
	CStudent Student;
	CStudent Student2;
	
	GetStudent(Student);
	GetStudent(Student2);

	DisplayStudent(Student);
	DisplayStudent(Student2);

}

