
#include "CSystemButton.h"


CSystemButton::CSystemButton()
{
	if( (btFd = open("/dev/pushbutton", O_RDONLY ) )  < 0  )
	{
		printf("/dev/pushbutton 열기 실패 \n");
		exit(1);
	}
}
CSystemButton::~CSystemButton()
{
	close( btFd );
}


int CSystemButton::getPressButton()
{
	int i;
	unsigned char btState;
	
	// 버튼의 상태값을 읽는다.
	// 눌려진 버튼은 비트값 1, 아니면 0 이다. 
	if( read( btFd, &btState, 1 ) < 0 )
	{
		printf("/dev/pushbutton 읽기 실패 \n");
		exit(1);
	}
	
	// 어느 버튼이 눌려 졌는지 찾는다.
	//만약 버튼이 두개 이상 눌러져 있다면 낮은 번지의 버튼이 눌려진 것으로 결정 된다. 
	i=0;
	while( i < 8 )
	{
		if( btState & (1<<i) )
		{
			return i;
		}

		i++;
	}

	return -1;

}
