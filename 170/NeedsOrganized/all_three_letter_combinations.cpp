void main()
{
	char guess[] = "aaa";

	while(guess[0] <= 'z')
	{
		guess[1] = 'a';
		while(guess[1] <= 'z')
		{
			guess[2] = 'a';
			while(guess[2] <= 'z')
			{
				cout << guess << endl;
				guess[2]++;
			}
			guess[1]++;
		}
		guess[0]++;
	}
}