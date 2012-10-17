#include<iostream>
#include<fstream.h>
using namespace std;

void WriteFile();
void ReadFile();

void main()
{
	WriteFile();
	ReadFile();
}

void WriteFile()
{
	ofstream fout;

	fout.open("numbers.txt", ios::binary);

	int Numbers[10] = {1,2,3,4,5,6,7,8,9,10};

	//Inserts a specified number of bytes from a buffer into the stream. 
	//If the underlying file was opened in text mode, additional carriage return characters 
	//may be inserted. The write function is useful for binary stream output.

	fout << Numbers[0];
	fout.write((char*)Numbers, sizeof(Numbers));

	//writes 0001|0002|0003|0004|0005|0006|0007|0008|0009|000A  if opend in binary
	//writes 0001|0002|0003|0004|0005|0006|0007|0008|0009|0A0D  if opend in text
	//will write 40 bytes, check the file size

	fout.close();	
}

void ReadFile()
{
	ifstream fin;

	fin.open("numbers.txt", ios::binary);

	int Numbers[10];
	
	//Extracts bytes from the stream until the limit nCount is reached or until the end of file is 
	//reached. The read function is useful for binary stream input.
	fin.read((char*)Numbers, sizeof(Numbers));

	fin.close();	

	for (int i = 0; i < 10; i ++)
	{
		cout << Numbers[i] << endl;
	}
}