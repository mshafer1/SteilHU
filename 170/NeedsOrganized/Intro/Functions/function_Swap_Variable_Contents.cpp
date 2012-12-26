//this example function demonstrates the use of
//  a temporary variable to swap the contents
//  of two variables

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
