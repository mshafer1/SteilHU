//For homework - complete the copy function, test it, submit on easel
//I have only provided a prototype for the copy function

#include <iostream>
 
using namespace std;
 
int average(const int list[], int count);
int total(const int list[], int count);
void displayList(const int list[], int count);
void copyList(int destination[], const int source[], int count);

void main()
{
	//strings
	// c style strings
	
	//array - list
	// array size - must be a whole number, 
	//	must be > 0, 
	//	must be a literal or const
	int grades[10]; // grades is a list of 10 int's
	for(int i = 0; i < 10; i++)
	{
		cout << "Enter grade " << i+1 << " :";
		cin >> grades[i];// grades sub i
	}
	displayList(grades,10);

	cout << "Total = "  << total (grades,10) << endl;
	cout << "Average = "  << average(grades,10) << endl;

	int grades2[10];
	copyList(grades2,grades,10);
	displayList(grades2,10);

	system("pause");
}

void displayList(const int list[], int count)
{
	for(int i = 0; i < 10; i++)
	{
		cout << i+1 << " = " << list[i] << endl;
	}
}

int total(const int list[], int count)
{
	int total = 0;
	for(int i = 0; i < count; i++)
	{
		total = total + list[i];
	}
	return total;
}

int average(const int list[], int count)
{
	return total(list,count)/count;
}

void copyList(int destination[], const int source[], int count)
{
}