#if !defined(_CSYSTEMLED_H)
#define _CSYSTEMLED_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

class CSystemLED
{
private:
	int ledFd;
public:
	CSystemLED();
	void turnOff( int index );
	void turnOn( int index );
};	

#endif
