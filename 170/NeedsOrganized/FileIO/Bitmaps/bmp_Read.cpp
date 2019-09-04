// This program reads from a bmp file and
// displays the results to the console.

#include<iostream>
#include<fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::ios;

int main()
{
	ifstream fin;
	char type[3] = "";
	int size;
	int offBits;
	int biSize;//  	4  	Header Size - Must be at least 40
	int biWidth;// 	4 	Image width in pixels
	int biHeight;// 	4 	Image height in pixels
	short biPlanes;// 	2 	Must be 1
	short biBitCount;// 	2 	Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
	int biCompression;// 	4 	Compression type (0 = uncompressed)
	int biSizeImage;// 	4 	Image Size - may be zero for uncompressed images
	int biXPelsPerMeter;// 	4 	Preferred resolution in pixels per meter
	int biYPelsPerMeter;// 	4 	Preferred resolution in pixels per meter
	int biClrUsed;// 	4 	Number Color Map entries that are actually used
	int biClrImportant;// 	4 	Number of significant colors

	fin.open("junk.bmp");

	fin.read(type,2);
	type[2] = '\0';
	fin.read((char*)&size,4);
	fin.seekg(4,ios::cur);
	fin.read((char*)&offBits,4);
	fin.read((char*)& biSize,4);//  	4  	Header Size - Must be at least 40
	fin.read((char*)& biWidth,4);// 	4 	Image width in pixels
	fin.read((char*)& biHeight,4);// 	4 	Image height in pixels
	fin.read((char*)& biPlanes,2);// 	2 	Must be 1
	fin.read((char*)& biBitCount,2);// 	2 	Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
	fin.read((char*)& biCompression,4);// 	4 	Compression type (0 = uncompressed)
	fin.read((char*)& biSizeImage,4);// 	4 	Image Size - may be zero for uncompressed images
	fin.read((char*)& biXPelsPerMeter,4);// 	4 	Preferred resolution in pixels per meter
	fin.read((char*)& biYPelsPerMeter,4);// 	4 	Preferred resolution in pixels per meter
	fin.read((char*)& biClrUsed,4);// 	4 	Number Color Map entries that are actually used
	fin.read((char*)& biClrImportant,4);// 	4 	Number of significant colors

	cout << "type = " << type << endl;
	cout << "size = " << size << endl;
	cout << "offBits = " << offBits << endl;
	cout <<  biSize<< endl;//  	4  	Header Size - Must be at least 40
	cout <<  biWidth<< endl;// 	4 	Image width in pixels
	cout <<  biHeight<< endl;// 	4 	Image height in pixels
	cout <<  biPlanes<< endl;// 	2 	Must be 1
	cout <<  biBitCount<< endl;// 	2 	Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
	cout <<  biCompression<< endl;// 	4 	Compression type (0 = uncompressed)
	cout <<  biSizeImage<< endl;// 	4 	Image Size - may be zero for uncompressed images
	cout <<  biXPelsPerMeter<< endl;// 	4 	Preferred resolution in pixels per meter
	cout <<  biYPelsPerMeter<< endl;// 	4 	Preferred resolution in pixels per meter
	cout <<  biClrUsed<< endl;// 	4 	Number Color Map entries that are actually used
	cout <<  biClrImportant<< endl;// 	4 	Number of significant colors

	unsigned char red;
	unsigned char blue;
	unsigned char green;


	int pixelsRead = 0;
	int bytesPerRow = biWidth * 3;

	int bytesToSkip = 0;
	
	while((bytesPerRow + bytesToSkip) % 4 != 0)
	{
		bytesToSkip++;
	}

	while(!fin.eof())
	{
		fin.read((char*)& blue,1);
		fin.read((char*)& green,1);
		fin.read((char*)& red,1);

		if(!fin.eof())
		{
			pixelsRead++;
			
			cout << "red = " << (int)red << endl;
			cout << "green = " << (int)green << endl;
			cout << "blue = " << (int)blue << endl << endl;

			if(pixelsRead % biWidth == 0)
			{
				cout << "Row Break" << endl;
				fin.seekg(bytesToSkip,ios::cur);
			}
		}
	}

	fin.close();
	return 0;

}