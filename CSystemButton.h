#if !defined(_CSYSTEMBUTTON_H)
#define _CSYSTEMBUTTON_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

class CSystemButton
{
private:
	int btFd;
public:
	CSystemButton();
	~CSystemButton();
	int getPressButton();

};



#endif
