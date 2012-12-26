#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	ifstream fin("clay.in");
	ofstream fout("clay.out");

	if(fin)
	{
		int NumberOfStudents;
		int x;
		int y;
		int z;
		int BullyClay;
		int VictimClay;
		string Name;
		string BullyName;
		string VictimName;

		fin >> NumberOfStudents;

		while(NumberOfStudents != -1)
		{
			fin >> x;
			fin >> y;
			fin >> z;
			fin >> Name;

			BullyClay = x*y*z;
			VictimClay = BullyClay;

			BullyName = Name;
			VictimName = Name;

			for(int i = 1; i < NumberOfStudents; i++)
			{
				fin >> x;
				fin >> y;
				fin >> z;
				fin >> Name;

				if(x*y*z < VictimClay)
				{
					VictimClay = x*y*z;
					VictimName = Name;
				}

				if(x*y*z > BullyClay)
				{
					BullyClay = x*y*z;
					BullyName = Name;
				}

			}

			fout << BullyName << " took clay from " << VictimName << "." << endl;

			fin >> NumberOfStudents;
		}
	}
	else
	{
		cout << "Can not find clay.in" << endl;
	}
	return 0;

}