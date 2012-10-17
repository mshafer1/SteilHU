#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

const int MAX_FILENAME_SIZE = 100;

void main()
{
    char fileName[MAX_FILENAME_SIZE];
    char type[3] = {0};
    unsigned int size;
    unsigned int offset;

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

    cout << "What is the name of the file you wish to open?" << endl;
    cin.getline(fileName, MAX_FILENAME_SIZE);

    ifstream fin;
    fin.open(fileName, ios::binary);

    fin.read(type,2);
    cout << "Type > " << type << endl;
    fin.read((char*)&size,4);
    cout << "Size > " << size << endl;
    fin.seekg(4,ios::cur);
    fin.read((char*)&offset,4);
    cout << "Offset > " << offset << endl;

    fin.read((char*)&biSize,4);
	cout << "biSize= " << biSize << endl;

    fin.read((char*)&biWidth,4);
	cout << "biWidth= " << biWidth << endl;

    fin.read((char*)&biHeight,4);
	cout << "biHeight= " << biHeight << endl;

    fin.read((char*)&biPlanes,2);
	cout << "biPlanes= " << biPlanes << endl;

    fin.read((char*)&biBitCount,2);
	cout << "biBitCount= " << biBitCount << endl;

    fin.read((char*)&biCompression,4);
	cout << "biCompression= " << biCompression << endl;

    fin.read((char*)&biSizeImage,4);
	cout << "biSizeImage= " << biSizeImage << endl;

    fin.read((char*)&biXPelsPerMeter,4);
	cout << "biXPelsPerMeter= " << biXPelsPerMeter << endl;

    fin.read((char*)&biYPelsPerMeter,4);
	cout << "biYPelsPerMeter= " << biYPelsPerMeter << endl;

    fin.read((char*)&biClrUsed,4);
	cout << "biClrUsed= " << biClrUsed << endl;

    fin.read((char*)&biClrImportant,4);
	cout << "biClrImportant= " << biClrImportant << endl;

	unsigned char blue;
	unsigned char green;
	unsigned char red;


	int extraBytesPerRow = 4 - ((biWidth * 3) % 4); //0,1,2,3
	
	if( extraBytesPerRow == 4 )
	{
		extraBytesPerRow  = 0;
	}

	for(unsigned int row = 0; row < biHeight; row++)
	{
		for(unsigned int column = 0; column < biWidth; column++)
		{
		    fin.read((char*)&blue,1);
		    fin.read((char*)&green,1);
		    fin.read((char*)&red,1);

			cout << "BGR = ";
			cout << setw(4) << (unsigned int)blue;
			cout << setw(4) << (unsigned int)green;
			cout << setw(4) << (unsigned int)red << endl;
		}
		//read the extra bytes
		//fout.write((char*)&i,extraBytesPerRow);
		fin.seekg( extraBytesPerRow, ios::cur );
		cout << endl;
	}


    fin.close();
}

