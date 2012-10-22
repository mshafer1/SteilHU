#include<iostream>

using namespace std;

int Occurances(const string& s,char c)
{
	int Result = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			Result++;
		}
	}


	return Result;
}

void main()
{
	string s = "Mississippi";
	cout << Occurances(s,'i') << endl;
}