//this file playes a .wav file (Windows only)

#include <windows.h>
#include <iostream>

//for this to work you must add winmm.lib to  
//menu -> Project | Properties
//tree -> Configuration Properties | Linker | Input | Additional Dependencies

int main()
{
       PlaySound( L"C:\\Program Files\\NetMeeting\\Blip.wav", NULL, SND_FILENAME | SND_SYNC );
       
       return 0;
}
