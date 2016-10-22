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
		switch(ran()%6)
		{
			case 0 :arr[i]=rand()%255; break;
			case 1 : arr[i]=0;break;
			case 2 : arr[i]=1;break;
			case 3 : arr[i]=1;break;
			case 4 : arr[i]=0;break;
			//case 5 : arr[i]=rand()%255; break;
			default : break;
		}
	}
}
void creatUcharArr(uchar **arr,u32 len)
{
	*arr=(uchar *)malloc(len*sizeof(uchar));
	memset(*arr,0,len*sizeof(uchar));
}
