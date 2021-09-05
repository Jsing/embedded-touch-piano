

#if !defined(_CKEYCOLORMANAGER_H)
#define _CKEYCOLORMANAGER_H

#include <qcolor.h>
#include <qstring.h>
#include <qvector.h>
#include <qmap.h>


class CKeyColorManager {
private:
        QMap< int , QColor > colorMap;
public:
	
        CKeyColorManager();
        QColor getColor( int id);
};

#endif
