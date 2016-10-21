#include "global.h"
void printBitsOfByte(uchar ch)
{
	uchar andx=1<<7;
	while(andx)
	{
		if(andx&ch)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		andx=(andx>>1);
	}
	printf("\n");
}
void randCreateUcharArr(uchar *arr,u32 len)
{
	srand(time(0)); 
	int i = 0;
	for( ; i < len; i++ )
	{
		
	}
}