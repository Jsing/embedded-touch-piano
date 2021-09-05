
#include "CSystemButton.h"


CSystemButton::CSystemButton()
{
	if( (btFd = open("/dev/pushbutton", O_RDONLY ) )  < 0  )
	{
		printf("/dev/pushbutton ���� ���� \n");
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
	
	// ��ư�� ���°��� �д´�.
	// ������ ��ư�� ��Ʈ�� 1, �ƴϸ� 0 �̴�. 
	if( read( btFd, &btState, 1 ) < 0 )
	{
		printf("/dev/pushbutton �б� ���� \n");
		exit(1);
	}
	
	// ��� ��ư�� ���� ������ ã�´�.
	//���� ��ư�� �ΰ� �̻� ������ �ִٸ� ���� ������ ��ư�� ������ ������ ���� �ȴ�. 
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
