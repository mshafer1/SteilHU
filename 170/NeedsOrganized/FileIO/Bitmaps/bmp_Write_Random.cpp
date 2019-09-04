//this program creates a bitmap image with random RGB values.

#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>

using std::ofstream;
using std::ios;
using std::cout;

int main()
{
	srand(time(0));

	ofstream fout;

	char type[3] = "BM";
	int size = 1000054;
	int offBits = 54;
	int biSize = 40;//  	4  	Header Size - Must be at least 40
	int biWidth = 1000;// 	4 	Image width in pixels
	int biHeight = 1000;// 	4 	Image height in pixels
	short biPlanes = 1;// 	2 	Must be 1
	short biBitCount = 24;// 	2 	Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
	int biCompression = 0;// 	4 	Compression type (0 = uncompressed)
	int biSizeImage = 1000000;// 	4 	Image Size - may be zero for uncompressed images
	int biXPelsPerMeter = 0;// 	4 	Preferred resolution in pixels per meter
	int biYPelsPerMeter = 0;// 	4 	Preferred resolution in pixels per meter
	int biClrUsed = 0;// 	4 	Number Color Map entries that are actually used
	int biClrImportant = 0;// 	4 	Number of significant colors

	fout.open("junk.bmp", ios::binary);

	cout << "writing header\n";

	fout.write(type,2);
	fout.write((char*)&size,4);
	fout.seekp(4,ios::cur);
	fout.write((char*)&offBits,4);
	fout.write((char*)& biSize,4);//  	4  	Header Size - Must be at least 40
	fout.write((char*)& biWidth,4);// 	4 	Image width in pixels
	fout.write((char*)& biHeight,4);// 	4 	Image height in pixels
	fout.write((char*)& biPlanes,2);// 	2 	Must be 1
	fout.write((char*)& biBitCount,2);// 	2 	Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
	fout.write((char*)& biCompression,4);// 	4 	Compression type (0 = uncompressed)
	fout.write((char*)& biSizeImage,4);// 	4 	Image Size - may be zero for uncompressed images
	fout.write((char*)& biXPelsPerMeter,4);// 	4 	Preferred resolution in pixels per meter
	fout.write((char*)& biYPelsPerMeter,4);// 	4 	Preferred resolution in pixels per meter
	fout.write((char*)& biClrUsed,4);// 	4 	Number Color Map entries that are actually used
	fout.write((char*)& biClrImportant,4);// 	4 	Number of significant colors

	unsigned char red;
	unsigned char blue;
	unsigned char green;

	for(int i = 0; i < 1000000; i++)
	{
		red = (rand() % 256);
		blue = (rand() % 256);
		green = (rand() % 256);

		fout.write((char*)& blue,1);
		fout.write((char*)& green,1);
		fout.write((char*)& red,1);
	
		/*if(i % biWidth == 0)
		{
			fout.seekp(3,ios::cur);
		}*/
	}

	fout.close();
	return 0;
}