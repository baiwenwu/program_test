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

struct BitsArray{
	uchar *arr;
	u32 headLen;
	u32 num;
	u32 bits;
	u32 mask;
	BitsArray(u32 bitsLen,u32 bits_t=3){
		bits=bits_t;
		mask=(1<<bits)-1;
		headLen=0;
		if(!bitsLen)
		{
			printf("输入参数错误!\n");
		}
		u32 headNum = bitsLen/blockSize;
		u32 headArrNum=( ( headNum*bits) >>bits ) +2;
		arr=(uchar *)malloc(headArrNum*sizeof(uchar));
		memset( arr , 0, headArrNum*sizeof(uchar));
		if(!arr)
		{
			printf("calloc head error! \n");
		}
	}
	int writeHeadForHybird(u16 type)
	{
		if(!arr)
		{
			printf("write type to headArray error!\n");
			return -1;
		}
		u32 words = headLen>>bits;
		u32 offset = headLen&7u;
		u16 tmp = arr[words];
		tmp=tmp<<8;
		tmp=(tmp>> ( 16 - bits - offset) )+type;
		tmp=tmp<<(16 - bits - offset);
		arr[words++]=( tmp >> 8) & 0xff;
		arr[words] = tmp & 0xff;
		headLen+=bits;
		num++;
		return 0;
	}
	u16 getValueFromHeadArray_N(u32 i)
	{
		u32 index = i*bits ;
		u32 words = index>>3;
		u32 offset = index &7;
		u16 tmp = arr[words++];
		tmp = tmp << 8;
		tmp +=arr[words];
		return ( tmp >> (16- bits - offset))&7;
	}
};
void arrayTest(uchar **arr)
{
	uchar *ch=(uchar *)malloc(10*sizeof(uchar));
	uchar i=1;
	for( ; i< 10;i++)
	{
		ch[i-1]='a'+i;
	}
	ch[9]='\0';
	*arr=ch;
}
int main()
{
	u32 headLen = 0 ;
	int NUM=1000000;

	u16 randArray[1000000]={0};
	BitsArray head(NUM*256,3);
	//head=createHeadArray(NUM*256);
	int i = 0 ;
	srand(time(0)); 
	for( ; i < NUM; i++ )
	{
		randArray[i] =rand() % 8;
		u16 t = randArray[i] ;
		head.writeHeadForHybird(randArray[i]);
	}
	//test
	for( i=0; i<NUM; i++)
	{
		u16 type_t=head.getValueFromHeadArray_N(i);
		if(randArray[i]!=type_t)
		{
			printf("%d error!\n",i);
		}
	}
	printf("the test finished!\n");


	uchar *arrTest=NULL;
	arrayTest(&arrTest);
	printf("%s\n",arrTest);

	return 0;
}