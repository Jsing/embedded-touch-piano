
#include "CKeyCreator.h"

CKeyCreator::CKeyCreator() {

}

void CKeyCreator::createKey(QVector<CKey> &keys , int  width, int  height) {

        // 키 생성 관련 변수
        CKey *pKey;
	QRect rect;
        QColor color;
        int id;

        // 좌표 관련 변수
	int right, left, top, bottom;
	int unitWidth, unitHeight;

	
        // 좌표 생성을 위한 초기값 설정
        unitWidth = width / 7;
	unitHeight = height; 
	top = 0;
	left = -unitWidth;

        id=0;
	int keySize = keys.size();
        while( id < keySize )
	{
		left = left + unitWidth;
		
                rect =  QRect( left, top, unitWidth, unitHeight);

                color = colorManager.getColor(id);

                pKey = new CKey( rect, color, id );
                keys.insert( id, pKey );
                id++;
	}


}

void CKeyCreator::deleteKey(QVector<CKey> &keys)
{
    int id;
    id=0;
    while( id < keys.size() )
    {
        delete keys[id];
        id++;
    }

}

