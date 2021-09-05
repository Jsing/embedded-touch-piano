
#include "CSoundManager.h"
#include <stdio.h>
CSoundManager::CSoundManager() {
	soundType = ELEC_SOUND;
}


void CSoundManager::startPlaying( int keyId) {
	QString filePath;
	int tmpSoundType;	
	if( (tmpSoundType = pushButton.getPressButton()) != -1 )
	{
		soundType = tmpSoundType;
	}
	
        filePath = soundFilePathManager.getFilePath( soundType,  keyId);
	QSound sound( filePath);
	sound.play() ;
}







