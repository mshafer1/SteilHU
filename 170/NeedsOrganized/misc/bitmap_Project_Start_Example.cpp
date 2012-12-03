#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<cstdlib>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ios;

struct BmpFileHeader
{
	char bfType[3];
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits;
};

struct BmpImageHeader
{
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	unsigned int biXPelsPerMeter;
	unsigned int biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
};

struct RgbTriple
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

void getFileName(string& fileName);
void getBitmapHeaderInfo(BmpFileHeader& bmpFileHeader, BmpImageHeader& bmpImageHeader, ifstream& bmpStream);
void getBitmapimageData(BmpImageHeader bmpImageHeader, ifstream& bmpStream, RgbTriple imageData[]);
void displayBitmapHeaderInfo(BmpFileHeader bmpFileHeader, BmpImageHeader bmpImageHeader);
void writeFile( string fileName, BmpFileHeader& bmpFileHeader, BmpImageHeader& bmpImageHeader, RgbTriple* imageData);
void addSaltAndPepper( BmpImageHeader& bmpImageHeader, RgbTriple* imageData);

int main()
{
	srand( (unsigned int) time( NULL ) );
	string fileName;
	BmpFileHeader bmpFileHeader;
	BmpImageHeader bmpImageHeader;
	RgbTriple* imageData = NULL;
	
	getFileName(fileName);
	ifstream bmpStream;
	bmpStream.open(fileName.c_str(), ios::binary);

	if( !bmpStream.fail() )
	{
		getBitmapHeaderInfo(bmpFileHeader, bmpImageHeader, bmpStream);
		displayBitmapHeaderInfo(bmpFileHeader, bmpImageHeader);

		imageData = new RgbTriple[bmpImageHeader.biWidth * bmpImageHeader.biHeight];
		getBitmapimageData(bmpImageHeader, bmpStream, imageData);
		cout << endl;

		addSaltAndPepper(bmpImageHeader, imageData);

		writeFile(fileName,bmpFileHeader, bmpImageHeader, imageData);


		delete[] imageData;
	}
	else
	{
		cout << fileName << " was not found." << endl;
	}
	
	return 0;
}

void getFileName(string& fileName)
{
	cout << "Filename: ";
	getline (cin, fileName);
}

void getBitmapHeaderInfo(BmpFileHeader& bmpFileHeader, 
						 BmpImageHeader& bmpImageHeader, 
						 ifstream& bmpStream)
{
	bmpStream.read(bmpFileHeader.bfType, 2);
	bmpStream.read((char*)&bmpFileHeader.bfSize, 4);
	bmpStream.read((char*)&bmpFileHeader.bfReserved1, 2);
	bmpStream.read((char*)&bmpFileHeader.bfReserved2, 2);
	bmpStream.read((char*)&bmpFileHeader.bfOffBits, 4);
	bmpStream.read((char*)&bmpImageHeader.biSize, 4);
	bmpStream.read((char*)&bmpImageHeader.biWidth, 4);
	bmpStream.read((char*)&bmpImageHeader.biHeight, 4);
	bmpStream.read((char*)&bmpImageHeader.biPlanes, 2);
	bmpStream.read((char*)&bmpImageHeader.biBitCount, 2);
	bmpStream.read((char*)&bmpImageHeader.biCompression, 4);
	bmpStream.read((char*)&bmpImageHeader.biSizeImage, 4);
	bmpStream.read((char*)&bmpImageHeader.biXPelsPerMeter, 4);
	bmpStream.read((char*)&bmpImageHeader.biYPelsPerMeter, 4);
	bmpStream.read((char*)&bmpImageHeader.biClrUsed, 4);
	bmpStream.read((char*)&bmpImageHeader.biClrImportant, 4);
	bmpFileHeader.bfType[2] = '\0';
}

void getBitmapimageData(BmpImageHeader bmpImageHeader, 
						ifstream& bmpStream, 
						RgbTriple imageData[])
{
	int index = 0;
	for(unsigned int row = 0; row < bmpImageHeader.biHeight; row++)
	{
		for (unsigned int column = 0; column < bmpImageHeader.biWidth; column++)
		{
			//int index = (row * bmpImageHeader.biWidth) + column;
			bmpStream.read((char*)&imageData[index].blue, 1);
			bmpStream.read((char*)&imageData[index].green, 1);
			bmpStream.read((char*)&imageData[index].red, 1);
			index++;
		}
		if ((bmpImageHeader.biWidth * 3) % 4 != 0)
		{
			bmpStream.seekg((4 - (bmpImageHeader.biWidth * 3) % 4), ios::cur);
		}
	}
}

void displayBitmapHeaderInfo(BmpFileHeader bmpFileHeader, BmpImageHeader bmpImageHeader)
{
	cout << "File Information:" << endl;
	cout << "bfType: " << bmpFileHeader.bfType << endl;
	cout << "bfSize: " << bmpFileHeader.bfSize << endl;
	cout << "bfReserved1: " << bmpFileHeader.bfReserved1 << endl;
	cout << "bfReserved2: " << bmpFileHeader.bfReserved2 << endl;
	cout << "bfOffBits: " << bmpFileHeader.bfOffBits << endl;
	cout << "biSize: " << bmpImageHeader.biSize << endl;
	cout << "biWidth: " << bmpImageHeader.biWidth << endl;
	cout << "biHeight: " << bmpImageHeader.biHeight << endl;
	cout << "biPlanes: " << bmpImageHeader.biPlanes << endl;
	cout << "biBitCount: " << bmpImageHeader.biBitCount << endl;
	cout << "biCompression: " << bmpImageHeader.biCompression << endl;
	cout << "biSizeImage: " << bmpImageHeader.biSizeImage << endl;
	cout << "biXPelsPerMeter: " << bmpImageHeader.biXPelsPerMeter << endl;
	cout << "biYPelsPerMeter: " << bmpImageHeader.biYPelsPerMeter << endl;
	cout << "biClrUSed: " << bmpImageHeader.biClrUsed << endl;
	cout << "biClrImportant: " << bmpImageHeader.biClrImportant << endl;
}

void writeFile( string fileName, BmpFileHeader& bmpFileHeader, BmpImageHeader& bmpImageHeader, RgbTriple* imageData)
{
	ofstream bmpStream(fileName.c_str(),ios::binary);

	bmpStream.write(bmpFileHeader.bfType, 2);
	bmpStream.write((char*)&bmpFileHeader.bfSize, 4);
	bmpStream.write((char*)&bmpFileHeader.bfReserved1, 2);
	bmpStream.write((char*)&bmpFileHeader.bfReserved2, 2);
	bmpStream.write((char*)&bmpFileHeader.bfOffBits, 4);
	bmpStream.write((char*)&bmpImageHeader.biSize, 4);
	bmpStream.write((char*)&bmpImageHeader.biWidth, 4);
	bmpStream.write((char*)&bmpImageHeader.biHeight, 4);
	bmpStream.write((char*)&bmpImageHeader.biPlanes, 2);
	bmpStream.write((char*)&bmpImageHeader.biBitCount, 2);
	bmpStream.write((char*)&bmpImageHeader.biCompression, 4);
	bmpStream.write((char*)&bmpImageHeader.biSizeImage, 4);
	bmpStream.write((char*)&bmpImageHeader.biXPelsPerMeter, 4);
	bmpStream.write((char*)&bmpImageHeader.biYPelsPerMeter, 4);
	bmpStream.write((char*)&bmpImageHeader.biClrUsed, 4);
	bmpStream.write((char*)&bmpImageHeader.biClrImportant, 4);

	int index = 0;
	char junk[4] = "";
	for(unsigned int row = 0; row < bmpImageHeader.biHeight; row++)
	{
		for (unsigned int column = 0; column < bmpImageHeader.biWidth; column++)
		{
			//int index = (row * bmpImageHeader.biWidth) + column;
			bmpStream.write((char*)&imageData[index].blue, 1);
			bmpStream.write((char*)&imageData[index].green, 1);
			bmpStream.write((char*)&imageData[index].red, 1);
			index++;
		}
		//write enough bytes to make this row have an even multiple of 4 bytes
		if ((bmpImageHeader.biWidth * 3) % 4 != 0)
		{
			bmpStream.write( junk,(4 - (bmpImageHeader.biWidth * 3) % 4));
		}
	}

	bmpStream.close();

}

void addSaltAndPepper( BmpImageHeader& bmpImageHeader, RgbTriple* imageData)
{
	for(unsigned int i = 0; i < bmpImageHeader.biHeight * bmpImageHeader.biWidth; i++)
	{
		switch(rand() % 10)
		{
			case 0:
				imageData[i].red = 0;
				imageData[i].green = 0;
				imageData[i].blue = 0;
				break;
			case 1:
				imageData[i].red = 255;
				imageData[i].green = 255;
				imageData[i].blue = 255;
				break;
		}
	}
}
