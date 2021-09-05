


#if !defined(_CSOUNDMANAGER_H)
#define _CSOUNDMANAGER_H


#include <qstring.h>
#include <qsound.h>
#include "CSoundFilePathManager.h"
#include "CSystemButton.h"

#define PIANO_SOUND 0
#define ELEC_SOUND 1


class CSoundManager{
private:
	CSoundFilePathManager soundFilePathManager;
	int soundType;
	CSystemButton pushButton;

	
public:

	CSoundManager();
        void startPlaying( int keyId);
};

#endif  //_CSOUNDMANAGER_H
