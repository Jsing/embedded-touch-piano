

#include "CKeyColorManager.h"

CKeyColorManager::CKeyColorManager() {
	int i;
	QColor color;

	i=0;
	//  "도" 빨강 
        color.setRgb( 255,0,0 );
        colorMap.insert( i, color );
	i++;

	// "레" 주황
        color.setRgb( 255,100,0);
        colorMap.insert(i , color );
	i++;
	// "미" yellow
        color.setRgb( 255,255,0);
        colorMap.insert( i, color );
	i++;	
	// "파" 초록
        color.setRgb( 0,255,0);
        colorMap.insert( i, color );
	i++;	
	// "솔" 파랑
        color.setRgb( 0,0,255);
        colorMap.insert( i, color );
	i++;	
	// "라" 남색
        color.setRgb( 0,0,153);
        colorMap.insert( i, color );
	i++;	
	// "시" 보라
        color.setRgb( 51,0,102);
        colorMap.insert( i, color );
	

}

QColor CKeyColorManager::getColor( int id) {
	
	return colorMap[ id ] ;
}

