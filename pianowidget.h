

#if !defined(_CPIANOWIDGET_H)
#define _CPIANOWIDGET_H


#include <qwidget.h>
#include <qevent.h>
#include <qvector.h>
#include <qstring.h>
#include <qpoint.h>
#include <qpainter.h>

#include "CSoundManager.h"
#include "CKey.h"
#include "Finder.h"
#include "CKeyCreator.h"
#include <stdio.h>
#include "CSystemLED.h"

class CPianoWidget : public QWidget {
private:
        QVector<CKey> keys;
        CSoundManager soundManager;
	CKey *pPressKey;
	bool mousePressed;
	CSystemLED led;
public:

        CPianoWidget();
        void mousePressEvent( QMouseEvent *event);
        void mouseReleaseEvent( QMouseEvent *event);
		void mouseMoveEvent( QMouseEvent *event);
        void paintEvent( QPaintEvent *event);
private:
	 void CPianoWidget::releaseKeyAction( CKey *pKey );
	 void CPianoWidget::pressKeyAction( CKey *pKey );
};

#endif  //_CPIANOWIDGET_H
