#include<iostream>
#include<string>

using namespace std;

//4.	Complete the following function.  It should replace all of the 
//		occurrences of the string s2 in the string s1 with string the s3. (10 points)
void Replace(string& s1, const string&s2, const string& s3)
{
	int index = (int)s1.find(s2); 

	while( index != string::npos)
	{
		s1.replace(index, s2.length(),s3);
		index = (int)s1.find(s2); 
	}
}


void main()
{
	string s = "This cow is cow a cow test cow";
	Replace(s,"cow","Bunny");

	cout << s << endl;
}