#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char uchar;

static u32 blockSize=256;
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
uchar *createHeadArray(u32 bitsLen)
{
	if(!bitsLen)
	{
		return NULL;
	}
	u32 headNum = bitsLen/blockSize;
	u32 headArrNum=( ( headNum*3) >>3 ) +2;
	uchar *head_t=(uchar *)malloc(headArrNum*sizeof(uchar));
	memset( head_t , 0, headArrNum*sizeof(uchar));
	if(!head_t)
	{
		printf("calloc head error! \n");
		return NULL;
	}
	return head_t;
}
int writeHeadForHybird(uchar *head,u32 *headLen,u16 type)
{
	if(!head||!headLen)
	{
		printf("write type to headArray error!\n");
		return -1;
	}
	u32 words = *headLen>>3;
	u32 offset = *headLen&7u;
	u16 tmp = head[words];
	tmp=tmp<<8;
	tmp=(tmp>> ( 13 - offset) )+type;
	tmp=tmp<<(13 - offset);
	head[words++]=( tmp >> 8) & 0xff;
	head[words] = tmp & 0xff;
	*headLen+=3;
	return 0;
}
u16 getValueFromHeadArray_N(uchar *head,u32 i)
{
	u32 index = i*3 ;
	u32 words = index>>3u;
	u32 offset = index &7u;
	u16 tmp = head[words++];
	tmp = tmp << 8;
	tmp +=head[words];
	return ( tmp >> (13 - offset))&7;
}
u16 getValueFromHeadArray_I(u32 index)
{
	return 0;
}
int main()
{
	uchar *head=NULL;
	u32 headLen = 0 ;
	int NUM=100000;

	u16 randArray[100000]={0};
	head=createHeadArray(NUM*256);
	int i = 0 ;
	srand(time(0)); 
	for( ; i < NUM; i++ )
	{
		randArray[i] =rand() % 8;
		u16 t = randArray[i] ;
		writeHeadForHybird( head, &headLen,randArray[i]);
	}
	//test
	for( i=0; i<NUM; i++)
	{
		u16 type_t=getValueFromHeadArray_N(head,i);
		if(randArray[i]!=type_t)
		{
			printf("%d error!\n",i);
		}
	}
	printf("the test finished!\n");
	return 0;
}