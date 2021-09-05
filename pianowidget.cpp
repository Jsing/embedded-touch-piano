
#include "pianowidget.h"
#include <stdio.h>



// 키 생성한다.
CPianoWidget::CPianoWidget() {

      int width, height;

      // 창 크기 설정
      width = 640;
      height = 480;
      resize(width,height);


      // 키 영역 구성
      keys.resize( 7);
      CKeyCreator keyCreator;
      keyCreator.createKey(keys, width, height );

      mousePressed = false;
      
	

}


void CPianoWidget::mousePressEvent( QMouseEvent *event) {
	
	if( mousePressed == false )
	{
		int keyId;

		// Find pressed key & save Pressed key
		QPoint pressPoint = event->pos();
		pPressKey = Finder::findKey( keys,  pressPoint );
		
		// do press Action
		pressKeyAction( pPressKey );
	}
	else
	{

		// do nothing
	}
}



void CPianoWidget::mouseReleaseEvent( QMouseEvent *event) {

        // Find released key 
		QPoint pressPoint = event->pos();
		CKey pReleaseKey = Finder::findKey( keys,  pressPoint ); 
	
		// do release Action
		releaseKeyAction( pReleaseKey );
}

void CPianoWidget::mouseMoveEvent( QMouseEvent *event)
{
	int keyId;
	CKey *pPressKeyByMoving;
       
	// Finding pressed key by Moving
    QPoint pressPoint = event->pos();
    pPressKeyByMoving = Finder::findKey( keys,  pressPoint );

	if( pPressKeyByMoving != pPressKey )
	{

		releaseKeyAction( pPressKey );

		pressKeyAction( pPressKeyByMoving );

	}
}

// 피아노 키들을 그린다.
void CPianoWidget::paintEvent( QPaintEvent *event) {


        QPainter painter(this);
        CKey *pKey;
        int id;

        id=0;
        while( id< 7 )
        {
                pKey = keys[ id ];
                pKey->paint( &painter );

                id++;
        }
}

void CPianoWidget::releaseKeyAction( CKey *pKey )
{
		mousePressed = false;

		// Restore color of pressed key
		pKey->setReleaseColor();

        // update released key's view
        this->update(pKey->getArea());
        
		keyId = pKey->getId();
		// Turn off released key's LED
		//unsigned char ledState=0x00;
		led.turnOff( keyId );


}

void CPianoWidget::pressKeyAction( CKey *pKey )
{
		// Replace color of press key
		pKey->setPressColor();

		// Update pressed key's view
		this->update(pKey->getArea());

		keyId = pKey->getId();
		// Turn on pressed key's LED
		//unsigned char ledState= 0x80>>keyId ;
		led.turnOn(  keyId );

		// start playing pressed key's sound
		soundManager.startPlaying( keyId );

		mousePressed = true;
}
