#include<fstream.h>


void main()
{
	ofstream Junk;

	Junk.open("junk.txt");

	Junk.width(10);
	Junk.setf(ios::left);
	Junk << "Bob";
	Junk.width(10);
	Junk.setf(ios::left);
	Junk << "Jones";


}