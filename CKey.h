


#if !defined(_CKEY_H)
#define _CKEY_H

#include <qcolor.h>
#include <qrect.h>
#include <qstring.h>
#include <qpainter.h>
#include <qbrush.h>


class CKey {
public:
    CKey();
    CKey( QRect area,  QColor color , int id);
	void paint( QPainter *painter);
	void setArea( QRect area);
	QRect getArea();
	bool contains( QPoint pt);
	void setColor( QColor);
	QColor getColor();
    int getId();
    void setId( int id);
	void setPressColor();
	void setReleaseColor();
private:
	QRect area;
	QColor color;
    int id;
	bool fPressed;
    QColor pressedColor;
};     

#endif
