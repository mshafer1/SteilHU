void main()
{
	char passWord[100] = "zzz";
	char guess[100];
	int guesses = 1;
	
	cin.getline(guess,100);

	while(strncmp(passWord,guess) != 0)
	{
		//cout <<"no" << endl;
		cin.getline(guess,100);
		guesses++;
	}
	cout << " it took you " << guesses << " guesses to find " << passWord << endl;
	cout << "You are in..." << endl;

}