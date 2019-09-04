#include<iostream>
#include<string>
using namespace std;

void main()
{
	string s = "This is the day the Lord has made"; //c++ string
	cout << s << endl;

	//the string got bigger(more memory) and we can use = for assignment
	s = "This is the day the Lord has made. I will rejoice and be glad in it.";
	cout << s << endl;
	
	string s2;
	s2 = s; //there is no need for strcpy
	cout << s2 << endl;

	string s3;
	//cin >> s3;	//stops a first white space
	getline(cin,s3);
	s2 = s2 + s3; //same as strcat
	s2.append(s3);
	cout << s2 << endl;

	cout << "the 3rd char in s2 is " << s2[2] << endl; 

	cout << s2.length() << endl;

	string s4 = s2.substr(4,10);
	cout << s4 << endl;

	int i  = s2.find("day");
	cout << i << endl;

	char sss[100];
	strcpy(sss,s2.c_str()); 

}