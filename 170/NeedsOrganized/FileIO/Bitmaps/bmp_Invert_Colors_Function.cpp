// This sample function inverts the colors of the pixels in a bitmap.

void invertColors(/*insert necessary parameters*/)
{
	for(int i = 0; i < width * height ; i++)
	{
		pixels[i].blue = unsigned char(255) - pixels[i].blue;
		pixels[i].green = unsigned char(255) - pixels[i].green;
		pixels[i].red = unsigned char(255) - pixels[i].red;
	}
}