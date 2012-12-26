#include "iostream.h"
#include "string.h"

struct CRadio
{
	float Station;
	char Band[3];
	bool On;
	int Volume;

	CRadio();
};

CRadio::CRadio()
{
	Station = 0;
	strcpy ( Band,"FM");
	On = false;
	Volume = 0;
}

void main()
{
	
	CRadio Radio;

	cout << Radio.On;

}