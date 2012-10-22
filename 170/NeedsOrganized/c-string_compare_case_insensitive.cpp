int CaseInsensitiveStringCompare(const char s1[], const char s2[])
{
	//assume that they are equal
	int Result = 0;
	int i = 0;

	while(s1[i] != '\0' && s2[i] != '\0' && Result == 0)
	{
		char c1 = toupper(s1[i]);
		char c2 = toupper(s2[i]);
		Result = c1 - c2;
		i++;

	}

	if (Result == 0)
	{
		Result = s1[i] - s2[i];
	}

	return Result;
}