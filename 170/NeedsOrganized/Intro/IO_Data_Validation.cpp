#include <iostream.h>
#include <stdlib.h>

bool ValidGrade(char Grade);
bool ValidCreditHour( int CreditHour);

using std::cout;
using std::cin;
using std::endl;


int main()
{
	char Grade;
	int CourseNumber = 1;

	cout << "For Course " << CourseNumber << ":" << endl;

	do
	{
		cout << "Grade? "; 
		cin >> Grade;
	}
	while (! ValidGrade(Grade));

	int CreditHour;

	do
	{
		cout << "Hours? ";
		cin >> CreditHour;
	}
	while (! ValidCreditHour(CreditHour));
}

bool ValidCreditHour( int CreditHour)
{
	bool Valid = false;

	if( CreditHour >= 0 && CreditHour <= 6)
	{
		Valid = true;
	}

	return Valid;
}

bool ValidGrade(char Grade)
{
	bool Valid = false;
	
	Grade = toupper( Grade );
	
	if (Grade == 'A' || Grade == 'B' || Grade == 'C' ||
		   Grade == 'D' || Grade == 'F')
	{
		Valid = true;
	}

	return Valid;
}





