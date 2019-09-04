// This program reads the data from the headers of a
// bitmap file and then displays the relevant information
// to the console.

#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
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

void getFileName(string& fileName);
void getBitmapHeaderInfo(BmpFileHeader& bmpFileHeader, BmpImageHeader& bmpImageHeader, ifstream& bmpStream);
void displayBitmapHeaderInfo(BmpFileHeader bmpFileHeader, BmpImageHeader bmpImageHeader);

int main()
{
	string fileName;
	BmpFileHeader bmpFileHeader;
	BmpImageHeader bmpImageHeader;
	
	getFileName(fileName);
	ifstream bmpStream;
	bmpStream.open(fileName.c_str(), ios::binary);

	if( !bmpStream.fail() )
	{
		getBitmapHeaderInfo(bmpFileHeader, bmpImageHeader, bmpStream);
		displayBitmapHeaderInfo(bmpFileHeader, bmpImageHeader);

		cout << endl;

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


