void strstrExample()
{
	char s[20];

	cin.getline(s,20);

	//if the address returned by strstr is not NULL 
	//the string is in the string
	if (strstr(s,"EFG") != NULL)
	{
		cout << "That is a good string, it has an 'E'" << endl;
		cout << "at address " << (int)strstr(s,"EFG") << endl;
		cout << "and index " << (int)(strstr(s,"EFG") - s) << endl;
		cout << "which is the " << (int)(strstr(s,"EFG") - s) + 1 << "th character" << endl;
	}
}