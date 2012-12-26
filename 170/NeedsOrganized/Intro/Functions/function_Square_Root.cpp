//this example function returns the square root of a number

float squareRoot(float x)
{
	float s = 2;
	float result = (x/s + s)/2;

	while(absoluteValue(result-s) >= .001)
	{   //uses another function that returns the absolute value
		s = result;
		result = (x/s + s)/2;
		cout << result << endl;
	}

	return result;
}
