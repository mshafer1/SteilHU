//this program writes text to a file

#include<fstream>

using std::ofstream;

int main()
{
	ofstream junk;

	junk.open("junk.txt"); // open file (create it if not there)

	junk << "Bob";

    junk.close(); // close the file
    
    return 0;
    //look for the file junk.txt
}
