void strchrExample()
{
	char s[20];

	cin.getline(s,20);

	//if the address returned by strchr is not NULL 
	//the char is in the string
	if (strchr(s,'E') != NULL)
	{
		cout << "That is a good string, it has an 'E'" << endl;
		cout << "at address " << (int)strchr(s,'E') << endl;
		cout << "and index " << (int)(strchr(s,'E') - s) << endl;
		cout << "which is the " << (int)(strchr(s,'E') - s) + 1 << "th character" << endl;
	}
}