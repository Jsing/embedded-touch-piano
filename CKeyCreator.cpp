
#include "CKeyCreator.h"

CKeyCreator::CKeyCreator() {

}

void CKeyCreator::createKey(QVector<CKey> &keys , int  width, int  height) {

        // Ű ���� ���� ����
        CKey *pKey;
	QRect rect;
        QColor color;
        int id;

        // ��ǥ ���� ����
	int right, left, top, bottom;
	int unitWidth, unitHeight;

	
        // ��ǥ ������ ���� �ʱⰪ ����
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

