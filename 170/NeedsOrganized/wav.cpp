
#include<windows.h>
using namespace std;

//for this to work you must add winmm.lib to your project properties
//Add it in the Linker | Input | Additional Dependencies

void main()
{
	PlaySound("C:\\junk.wav",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
}