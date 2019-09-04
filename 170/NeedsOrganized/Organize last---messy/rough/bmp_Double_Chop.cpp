// runtime error, this is a longer .cpp file and
// there are many simlar ones so I'm moving it to rough as-is

#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::ios_base;

struct Pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

struct Header
{
	char bfType[3];		//	2  	The characters "BM"	
	int bfSize;			//	4 	The size of the file in bytes
	int bfOffBits;		//	4 	Offset to start of Pixel Data
	short bfReserved1; 	//	2 	Unused - must be zero
	short bfReserved2; 	//	2 	Unused - must be zero
	int biSize;			// 	4  	Header Size - Must be at least 40
	int biWidth;		// 	4 	Image width in pixels
	int biHeight;		// 	4 	Image height in pixels
	short biPlanes;		// 	2 	Must be 1
	short biBitCount;	// 	2 	Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
	int biCompression;	// 	4 	Compression type (0 = uncompressed)
	int biSizeImage;	// 	4 	Image Size - may be zero for uncompressed images
	int biXPelsPerMeter;// 	4 	Preferred resolution in pixels per meter
	int biYPelsPerMeter;// 	4 	Preferred resolution in pixels per meter
	int biClrUsed;		// 	4 	Number Color Map entries that are actually used
	int biClrImportant;	// 	4 	Number of significant colors
};

struct Picture
{
	Pixel* pixels;
	Header header;
	char fileName[100];
};

void readBitmap( Picture& picture );
void writeBitmap( const Picture& picture );
void displayFileHeader( Header& header );
void doubleChop( Picture& picture );

int main()
{
	Picture picture;

	//get the filename
	cout << "bmp file to edit> ";
	cin.getline(picture.fileName,100);

	readBitmap( picture );

	displayFileHeader( picture.header );
	cout << 1 << endl;
	doubleChop( picture );
	cout << 2 << endl;

	writeBitmap( picture );

	//give the dynamic memory back to the OS
	delete[] picture.pixels;
	
	return 0;
}

void doubleChop( Picture& picture )
{
	Pixel* newPixels = new Pixel[picture.header.biWidth * picture.header.biHeight / 4];

	int pixelsCopied = 0;
	for(int row = picture.header.biHeight/2; row < picture.header.biHeight; row++)
	{
		for(int column = 0; column < picture.header.biWidth/2; column++)
		{
			newPixels[pixelsCopied] = picture.pixels[row * picture.header.biWidth + column ];
			pixelsCopied++;
		}
	}
	cout << "pixelsCopied" << pixelsCopied << endl;

	picture.header.biWidth /= 2;
	picture.header.biHeight /= 2;

	delete[] picture.pixels;
	picture.pixels = newPixels;
}


void readBitmap( Picture& picture )
{
	ifstream fin;
	fin.open(picture.fileName, ios_base::binary);

	fin.read(picture.header.bfType,2);
	picture.header.bfType[2] = '\0';
	fin.read((char*)& picture.header.bfSize,4);
	fin.seekg(4,ios::cur);
	fin.read((char*)& picture.header.bfOffBits,4);
	fin.read((char*)& picture.header.biSize,4);
	fin.read((char*)& picture.header.biWidth,4);
	fin.read((char*)& picture.header.biHeight,4);
	fin.read((char*)& picture.header.biPlanes,2);
	fin.read((char*)& picture.header.biBitCount,2);
	fin.read((char*)& picture.header.biCompression,4);
	fin.read((char*)& picture.header.biSizeImage,4);
	fin.read((char*)& picture.header.biXPelsPerMeter,4);
	fin.read((char*)& picture.header.biYPelsPerMeter,4);
	fin.read((char*)& picture.header.biClrUsed,4);
	fin.read((char*)& picture.header.biClrImportant,4);

	//dynamicly allocate space for all of the pixels
	picture.pixels = new Pixel[picture.header.biWidth * picture.header.biHeight];

	int bytesPerRow = picture.header.biWidth * 3;
	int bytesToSkip = 0;
	
	while((bytesPerRow + bytesToSkip) % 4 != 0)
	{
		bytesToSkip++;
	}
	cout << "Skipping " << bytesToSkip << "When reading" << endl; 

	for(int i = 0; i < picture.header.biWidth * picture.header.biHeight; i++)
	{
		if(i % picture.header.biWidth == 0 && i != 0)
		{
			fin.seekg(bytesToSkip,ios::cur);
		}

		fin.read((char*)&(picture.pixels[i].blue),1);
		fin.read((char*)&(picture.pixels[i].green),1);
		fin.read((char*)&(picture.pixels[i].red),1);

	}
	fin.close();
}

void writeBitmap( const Picture& picture )
{
	ofstream fout;
	fout.open(picture.fileName,ios_base::binary);

	int junk = 0;

	//write the header
	fout.write(picture.header.bfType,2);
	fout.write((char*)&picture.header.bfSize,4);
	fout.write((char*)&junk,4); // this is junk it cound be any 4 bytes
	fout.write((char*)&picture.header.bfOffBits,4);
	fout.write((char*)&picture.header.biSize,4);
	fout.write((char*)&picture.header.biWidth,4);
	fout.write((char*)&picture.header.biHeight,4);
	fout.write((char*)&picture.header.biPlanes,2);
	fout.write((char*)&picture.header.biBitCount,2);
	fout.write((char*)&picture.header.biCompression,4);
	fout.write((char*)&picture.header.biSizeImage,4);
	fout.write((char*)&picture.header.biXPelsPerMeter,4);
	fout.write((char*)&picture.header.biYPelsPerMeter,4);
	fout.write((char*)&picture.header.biClrUsed,4);
	fout.write((char*)&picture.header.biClrImportant,4);

	int bytesPerRow = picture.header.biWidth * 3;
	int bytesToSkip = 0;
	
	while((bytesPerRow + bytesToSkip) % 4 != 0)
	{
		bytesToSkip++;
	}
	cout << "Skipping " << bytesToSkip << "When writing" << endl; 

	//write the pixels
	for(int i = 0; i < picture.header.biWidth * picture.header.biHeight; i++)
	{
		if(i % picture.header.biWidth == 0 && i != 0)
		{
			fout.write((char*)& junk, bytesToSkip);
		}

		fout.write((char*)& (picture.pixels[i].blue),1);
		fout.write((char*)& (picture.pixels[i].green),1);
		fout.write((char*)& (picture.pixels[i].red),1);
	}

	fout.close();
}


void displayFileHeader( Header& header )
{
	cout << "type = " << header.bfType << endl;
	cout << "size = " << header.bfSize << endl;
	cout << "offBits = " << header.bfOffBits << endl;
	cout <<  header.biSize<< endl;
	cout <<  header.biWidth<< endl;
	cout <<  header.biHeight<< endl;
	cout <<  header.biPlanes<< endl;
	cout <<  header.biBitCount<< endl;
	cout <<  header.biCompression<< endl;
	cout <<  header.biSizeImage<< endl;
	cout <<  header.biXPelsPerMeter<< endl;
	cout <<  header.biYPelsPerMeter<< endl;
	cout <<  header.biClrUsed<< endl;
	cout <<  header.biClrImportant<< endl;
}
