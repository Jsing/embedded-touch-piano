

#if !defined(_CKEYCREATOR_H)
#define _CKEYCREATOR_H

#include "CKeyColorManager.h"
#include "CKey.h"

#include <qvector.h>
#include <qrect.h>
#include <qstring.h>
#include <qcolor.h>


class CKeyCreator {
public:
        CKeyCreator();
        void createKey(QVector<CKey> &keys, int  width,  int height);
        void deleteKey(QVector<CKey> &keys);
private:
	CKeyColorManager colorManager;
};

#endif
