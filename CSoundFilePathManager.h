

#if !defined(_CSOUNDFILEPATHMANAGER_H)
#define _CSOUNDFILEPATHMANAGER_H

#include <qstring.h>
#include <qarray.h>
#include <qmap.h>
#include "CKey.h"


class CSoundFilePathManager {
public:
	CSoundFilePathManager();
	QString getFilePath(int type, int id);
private:
	//QMap<int, QMap<int,QString> > typeMap;
	//QMap<int, QString> filePathMap;
	char db[8][7][100];
};

#endif  //_CFILEPATHMANAGER_H
