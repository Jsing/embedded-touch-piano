

#include "CKey.h"

CKey::CKey()
{
    area = QRect(0,0,0,0);
    color = QColor(255,255,255);
    id = -1;
    fPressed = false;
    pressedColor = QColor(255,255,255);
}

CKey::CKey( QRect area,  QColor color , int id) {
	this->area = area;
	this->color = color;
	this->id = id;
	fPressed = false;
    pressedColor = QColor(255,255,255);
}

void CKey::paint( QPainter *painter) {
	QBrush oldBrush;

	// 이전의 브러쉬 저장 
	oldBrush = painter->brush();

	// 키가 눌려져 있으면 눌려짐을 표현하는 색을 설정하고 아니면 자신의 원색을 설정한다.
	if( fPressed == true )
	{
		painter->setBrush( pressedColor );
	}
	else 
	{
        painter->setBrush( color );
	}
	// 자신의 사각형을 그린다.
	painter->drawRect( area );

	// 브러쉬 원상 복구
	painter->setBrush( oldBrush );
}

void CKey::setArea( QRect area) {
	this->area = area;
}

QRect CKey::getArea() {
	return area;
}

bool CKey::contains(QPoint pt) {
        return area.contains( pt );
}

void CKey::setColor( QColor color) {
	this->color = color ;
}

QColor CKey::getColor() {
	return color;
}

int CKey::getId() {
	return id;
}

void CKey::setId( int id) {
	this->id = id;
}

void CKey::setPressColor() {
	fPressed = true;
}

void CKey::setReleaseColor() {
	fPressed = false;
}

