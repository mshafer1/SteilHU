//Kevin Jensen
//Steil 9:00 Daily
//COMP 170

//Draws a bitmap of the US Flag
#include<iostream>
#include<fstream>

using std::ofstream;
using std::ios;

int main()
{
    ofstream fout;

    char type[3] = "BM";
    int size = 1152054;
    int offBits = 54;
    int biSize = 40;//   4   Header Size - Must be at least 40
    int biWidth = 800;//     4   Image width in pixels
    int biHeight = 480 ;//   4   Image height in pixels
    short biPlanes = 1;//    2   Must be 1
    short biBitCount = 24;//     2   Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
    int biCompression = 0;//     4   Compression type (0 = uncompressed)
    int biSizeImage = 1152000;//     4   Image Size - may be zero for uncompressed images
    int biXPelsPerMeter = 0;//   4   Preferred resolution in pixels per meter
    int biYPelsPerMeter = 0;//   4   Preferred resolution in pixels per meter
    int biClrUsed = 0;//     4   Number Color Map entries that are actually used
    int biClrImportant = 0;//    4   Number of significant colors

    fout.open("Flag.bmp", ios::binary);

    fout.write(type,2);
    fout.write((char*)&size,4);
    fout.seekp(4,ios::cur);
    fout.write((char*)&offBits,4);
    fout.write((char*)& biSize,4);//     4   Header Size - Must be at least 40
    fout.write((char*)& biWidth,4);//    4   Image width in pixels
    fout.write((char*)& biHeight,4);//   4   Image height in pixels
    fout.write((char*)& biPlanes,2);//   2   Must be 1
    fout.write((char*)& biBitCount,2);//     2   Bits per pixel - 1, 2, 4, 8, 16, 24, or 32
    fout.write((char*)& biCompression,4);//  4   Compression type (0 = uncompressed)
    fout.write((char*)& biSizeImage,4);//    4   Image Size - may be zero for uncompressed images
    fout.write((char*)& biXPelsPerMeter,4);//    4   Preferred resolution in pixels per meter
    fout.write((char*)& biYPelsPerMeter,4);//    4   Preferred resolution in pixels per meter
    fout.write((char*)& biClrUsed,4);//  4   Number Color Map entries that are actually used
    fout.write((char*)& biClrImportant,4);//     4   Number of significant colors

    unsigned char red;
    unsigned char blue;
    unsigned char green;

    //Draws the Stripes
    for(int k = 0; k < 6; k++)
    {
        red = 191;
        blue = 48;
        green = 10;
        for(int i = 0; i < 29600; i++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }

        red = 255;
        blue = 255;
        green = 255;
        for(int i = 0; i < 29600; i++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
    }
    red = 191;
    blue = 48;
    green = 10;
    for(int i = 0; i < 29600; i++)
    {
        fout.write((char*)& blue,1);
        fout.write((char*)& green,1);
        fout.write((char*)& red,1);
    }
    
    //Draws the blue field
    int index = 532851;
    for(int j = 0; j < 258; j++)
    {
        fout.seekp(index);
        red = 0;
        blue = 104;
        green = 40;
        for(int i = 0; i < 319; i++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        index = index + 2400;
    }
    
    //Draws the stars
    index = 571314;
    for(int y = 0; y < 64; y++)
    {
        fout.seekp(index);
        red = 255;
        blue = 255;
        green = 255;
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        fout.seekp(index + 42);
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        fout.seekp(index + 2400);
        for(int p = 0; p < 2; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 2439);
        for(int p = 0; p < 2; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 4800);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 4836);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 7203);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 7233);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 9603);
        for(int p = 0; p < 4; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 9630);
        for(int p = 0; p < 4; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 12006);
        for(int p = 0; p < 4; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 12027);
        for(int p = 0; p < 4; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 14406);
        for(int p = 0; p < 5; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 14424);
        for(int p = 0; p < 5; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 16809);
        for(int p = 0; p < 9; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 19209);
        for(int p = 0; p < 9; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 21609);
        for(int p = 0; p < 9; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 24006);
        for(int p = 0; p < 11; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 26403);
        for(int p = 0; p < 13; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 28800);
        for(int p = 0; p < 15; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 31197);
        for(int p = 0; p < 17; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 33594);
        for(int p = 0; p < 19; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 36015);
        for(int p = 0; p < 5; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 38415);
        for(int p = 0; p < 5; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 40815);
        for(int p = 0; p < 5; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 43218);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 45618);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 48018);
        for(int p = 0; p < 3; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 50421);
        for(int p = 0; p < 1; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        fout.seekp(index + 52821);
        for(int p = 0; p < 1; p++)
        {
            fout.write((char*)& blue,1);
            fout.write((char*)& green,1);
            fout.write((char*)& red,1);
        }
        
        if(y < 5)
        {
            index = index + 159;
        }
        if (y == 5)
        {
            index = index + 61686;
        }
        if (y > 5 && y < 10)
        {
            index = index + 159;
        }
        if (y == 11)
        {
            index = index + 61686;
        }
        if (y > 12 && y < 18)
        {
            index = index + 159;
        }
        if (y == 19)
        {
            index = index + 61686;
        }
        if (y > 20 && y < 25)
        {
            index = index + 159;
        }
        if (y == 26)
        {
            index = index + 61686;
        }
        if (y > 27 && y < 33)
        {
            index = index + 159;
        }
        if (y == 34)
        {
            index = index + 61686;
        }
        if (y > 35 && y < 40)
        {
            index = index + 159;
        }
        if (y == 41)
        {
            index = index + 61686;
        }
        if (y > 42 && y < 48)
        {
            index = index + 159;
        }
        if (y == 49)
        {
            index = index + 61686;
        }
        if (y > 50 && y < 55)
        {
            index = index + 159;
        }
        if (y == 56)
        {
            index = index + 61686;
        }
        if (y > 57 && y < 63)
        {
            index = index + 159;
        }
    }
	return 0;
}