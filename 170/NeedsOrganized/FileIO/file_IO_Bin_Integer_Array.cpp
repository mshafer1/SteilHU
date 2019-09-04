//This program writes an array of integers to a file in binary using
//ofstream::write(), and then reads the file using ifstream::read().

#include<iostream>
#include<fstream>

using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::ios;
using std::endl;

void writeFile();
void readAndDisplayFile();

int main()
{
	writeFile();
	readAndDisplayFile();
	cout << endl << "Press enter.";
	cin.get();
	return 0;
}

void writeFile()
{
	ofstream fout;

	fout.open("numbers.txt", ios::binary);

	int Numbers[10] = {1,2,3,4,5,6,7,8,9,10}; //40 byte array

	fout.write((char*)Numbers, sizeof(Numbers));
		// ^^ Inserts a specified number of bytes from a buffer into the stream. 
		// If the underlying file was opened in text mode, additional carriage return 
		//characters may be inserted. The write function is useful for binary stream 
		// output.

		//writes 0001|0002|0003|0004|0005|0006|0007|0008|0009|000A  if opened in binary
		//writes 0001|0002|0003|0004|0005|0006|0007|0008|0009|0A0D  if opened in text

	fout.close();
}

void readAndDisplayFile()
{
	ifstream fin;

	fin.open("numbers.txt", ios::binary);

	int Numbers[10];
	
	fin.read((char*)Numbers, sizeof(Numbers));
		// ^^ Extracts bytes from the stream until the limit nCount is reached or 
		// until the end of file is reached. The read function is useful for 
		// binary stream input.
	
	fin.close();	

	for (int i = 0; i < 10; i ++)
	{
		cout << Numbers[i] << endl;
	}
}