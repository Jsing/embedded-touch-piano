#include "CSystemLED.h"

CSystemLED::CSystemLED()
{
	unsigned char ledState;
	if( (ledFd = open("/dev/led", O_WRONLY ))< 0 )
	{
		printf(" /dev/led open Fail!! \n");
		exit(1);
	}
	
	ledState = 0X00;
	if( write( ledFd, &ledState , 1 ) < 0 )
	{
		printf(" /dev/led write Fail!! \n");
		exit(1);
	}

}

void CSystemLED::turnOn( int index )
{
	unsigned char ledState;

	ledState = 0x80>>index;

	if( write( ledFd, &ledState , 1 ) < 0 )
	{
		printf(" /dev/led write Fail!! \n");
		exit(1);
	}
}

void CSystemLED::turnOff( int index )
{
	unsigned char ledState;

	ledState = 0x00;

	if( write( ledFd, &ledState , 1 ) < 0 )
	{
		printf(" /dev/led write Fail!! \n");
		exit(1);
	}
}
