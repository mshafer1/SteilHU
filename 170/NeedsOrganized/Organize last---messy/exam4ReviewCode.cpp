#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	char s[] = "This is a test";
	char* p  = strtok(s," ");

	while(p != NULL)
	{
		cout << p << endl;
		p  = strtok(NULL," ");
	}

	cout << s << endl;
}

//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//void main()
//{
//	char fileNameIn[100];
//	char fileNameOut[100];
//
//
//	ifstream fin;
//	do
//	{
//		fin.clear();
//		cout << "What file do you want to copy?";
//		cin.getline(fileNameIn,100);
//
//		fin.open(fileNameIn);
//	}
//	while(fin.fail());
//
//	cout << "What do you want to name the copy?";
//	cin.getline(fileNameOut,100);
//
//	ofstream fout(fileNameOut);
//
//	char line[1000];
//
//	while(!fin.eof())
//	{
		fin.get(c);
		fout << c;
//		fin.getline(line,1000);
//		fout << line << endl;
//	}
//
//	fin.close();
//	fout.close();
//
//}


