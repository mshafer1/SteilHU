//this program shows how to incorporate command line arguments into your program

#include<iostream>

int main( int argc, char* argv[] )
// argc os the number of arguments given
// argv is a pointer to an array of the arguments
// 		don't forget: the first argument (argv[0]) is always the first input before whitespace
//			- usually something like "C:/Users/Me/Desktop/myProgram.exe"

{
	std::cout << "\nhere are your arguments:";
	
	for(int i = 0; i < argc; i++)
	{
		std::cout  << std::endl << argv[i];
	}
	
	std::cout << std::endl;
	
	return 0;
}
// console looks like this:
//						
// C:\myProgram.exe -these --are arguments	[file followed by arguments, press enter]
//
// here are your arguments:					[program runs]
// C:\myprogram.exe
// -these
// --are
// arguments
//											[end of program]
// C:\										[back to console]
