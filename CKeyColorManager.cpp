

#include "CKeyColorManager.h"

CKeyColorManager::CKeyColorManager() {
	int i;
	QColor color;

	i=0;
	//  "��" ���� 
        color.setRgb( 255,0,0 );
        colorMap.insert( i, color );
	i++;

	// "��" ��Ȳ
        color.setRgb( 255,100,0);
        colorMap.insert(i , color );
	i++;
	// "��" yellow
        color.setRgb( 255,255,0);
        colorMap.insert( i, color );
	i++;	
	// "��" �ʷ�
        color.setRgb( 0,255,0);
        colorMap.insert( i, color );
	i++;	
	// "��" �Ķ�
        color.setRgb( 0,0,255);
        colorMap.insert( i, color );
	i++;	
	// "��" ����
        color.setRgb( 0,0,153);
        colorMap.insert( i, color );
	i++;	
	// "��" ����
        color.setRgb( 51,0,102);
        colorMap.insert( i, color );
	

}

QColor CKeyColorManager::getColor( int id) {
	
	return colorMap[ id ] ;
}

