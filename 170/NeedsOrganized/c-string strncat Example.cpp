void strncatExample()
{
	char s[20];
	char s2[20];

	int i;
	//assume that i is >= 0
	cin >> i;
	cin.get(); //trashes the \n that is still in the input buffer

	cin.getline(s,20);
	cin.getline(s2,20);


	if (strlen(s) + i< 20)
	{
		strncat(s,s2,i);
	}
	else
	{
		cout << "Sorry too big" << endl;
	}

	cout << s << endl;
}