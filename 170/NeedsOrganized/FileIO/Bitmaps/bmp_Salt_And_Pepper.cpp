//this sample function adds "salt and pepper" to a bitmap image

void addSaltAndPepper(/*insert appropriate parameters here*/)
{
	//you will need to seed with srand() in main
	
	for(unsigned int i = 0; i < height * width; i++)
	{
		switch(rand() % 10) // only alters 2 in 10 pixels
		{
			case 0:
				pixel[i].red = 0;
				pixel[i].green = 0;
				pixel[i].blue = 0;
				break;
			case 1:
				pixel[i].red = 255;
				pixel[i].green = 255;
				pixel[i].blue = 255;
				break;
		}
	}
}