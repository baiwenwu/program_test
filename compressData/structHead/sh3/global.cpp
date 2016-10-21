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
void randFillUcharArr(uchar *arr,u32 len)
{
	if(!arr)
	{
		printf("生成随机字符串失败!\n");
		return ;
	}
	srand(time(0)); 
	u32 i = 0;
	for( ; i < len; i++ )
	{
		switch(ran()%4)
		{
			case:
		}
	}
}