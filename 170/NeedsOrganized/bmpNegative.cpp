#include<iostream>
#include<fstream>
using namespace std;

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

void readBitmap( Header& header, Pixel*& pixels );
void writeBitmap( const Header& header, const Pixel pixels[]);
void displayFileHeader( Header& header );
void invertColors( const Header& header, Pixel pixels[] );

void main()
{
	ifstream fin;

	Pixel* pixels;
	Header header;

	readBitmap( header, pixels );

	displayFileHeader( header );
	invertColors( header, pixels );

	writeBitmap(header, pixels);

	//give the dynamic memory back to the OS
	delete[] pixels;
}

void readBitmap( Header& header, Pixel*& pixels )
{
	ifstream fin;
	fin.open("junk.bmp", ios_base::binary);

	fin.read(header.bfType,2);
	header.bfType[2] = '\0';
	fin.read((char*)& header.bfSize,4);
	fin.seekg(4,ios::cur);
	fin.read((char*)& header.bfOffBits,4);
	fin.read((char*)& header.biSize,4);
	fin.read((char*)& header.biWidth,4);
	fin.read((char*)& header.biHeight,4);
	fin.read((char*)& header.biPlanes,2);
	fin.read((char*)& header.biBitCount,2);
	fin.read((char*)& header.biCompression,4);
	fin.read((char*)& header.biSizeImage,4);
	fin.read((char*)& header.biXPelsPerMeter,4);
	fin.read((char*)& header.biYPelsPerMeter,4);
	fin.read((char*)& header.biClrUsed,4);
	fin.read((char*)& header.biClrImportant,4);

	//dynamicly allocate space for all of the pixels
	pixels = new Pixel[header.biWidth * header.biHeight];

	int bytesPerRow = header.biWidth * 3;
	int bytesToSkip = 0;
	
	while((bytesPerRow + bytesToSkip) % 4 != 0)
	{
		bytesToSkip++;
	}

	for(int i = 0; i < header.biWidth * header.biHeight; i++)
	{
		if(i % header.biWidth == 0 && i != 0)
		{
			fin.seekg(bytesToSkip,ios::cur);
		}

		fin.read((char*)&(pixels[i].blue),1);
		fin.read((char*)&(pixels[i].green),1);
		fin.read((char*)&(pixels[i].red),1);
	}
	fin.close();
}

void writeBitmap( const Header& header, const Pixel pixels[])
{
	ofstream fout;
	fout.open("junk.bmp",ios_base::binary);

	int junk = 0;

	//write the header
	fout.write(header.bfType,2);
	fout.write((char*)&header.bfSize,4);
	fout.write((char*)&junk,4); // this is junk it cound be any 4 bytes
	fout.write((char*)&header.bfOffBits,4);
	fout.write((char*)&header.biSize,4);
	fout.write((char*)&header.biWidth,4);
	fout.write((char*)&header.biHeight,4);
	fout.write((char*)&header.biPlanes,2);
	fout.write((char*)&header.biBitCount,2);
	fout.write((char*)&header.biCompression,4);
	fout.write((char*)&header.biSizeImage,4);
	fout.write((char*)&header.biXPelsPerMeter,4);
	fout.write((char*)&header.biYPelsPerMeter,4);
	fout.write((char*)&header.biClrUsed,4);
	fout.write((char*)&header.biClrImportant,4);

	int bytesPerRow = header.biWidth * 3;
	int bytesToSkip = 0;
	
	while((bytesPerRow + bytesToSkip) % 4 != 0)
	{
		bytesToSkip++;
	}

	//write the pixels
	for(int i = 0; i < header.biWidth * header.biHeight; i++)
	{
		if(i % header.biWidth == 0 && i != 0)
		{
			fout.write((char*)& junk, bytesToSkip);
		}

		fout.write((char*)& (pixels[i].blue),1);
		fout.write((char*)& (pixels[i].green),1);
		fout.write((char*)& (pixels[i].red),1);
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

void invertColors( const Header& header, Pixel pixels[] )
{
	for(int i = 0; i < header.biWidth * header.biHeight ; i++)
	{
		pixels[i].blue = unsigned char(255) - pixels[i].blue;
		pixels[i].green = unsigned char(255) - pixels[i].green;
		pixels[i].red = unsigned char(255) - pixels[i].red;
	}
}