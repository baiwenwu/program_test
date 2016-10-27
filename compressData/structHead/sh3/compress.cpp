#include "compress.h"
u32 getFirstBit(uchar *src,u32 index)
{//数值大于零则肯定是1,数值等于0肯定为0
	u32 words=index>>3;
	u32 offset=(index&7);
	return src[words]&(128>offset);
}
u32 getRuns(uchar *src,u32 index,u32 bitsLen)
{
	u32 num=1;
	u32 words=index>>3;
	u32 offset=index&7;
	uchar andx=128>>offset;
	uchar bit=src[words]&andx;
	andx=andx>>1;
	if(bit)
	{//为1
		while(andx&)
	}
	else
	{//为0

	}
	return 0;
}
int compressMainFun(uchar* src,uchar *cdata,bitArray* head,u32 bitsLen)
{
	if(!src||!cdata||!head||!bitLen)
	{
		printf("the parameters of compress main function is error!\n");
		return -1;
	}
	*head=createHeadArray(bitsLen);
 	u32 index=0;
 	uchar firstBit;
 	u32 runs_t=0;
 	u32 *runsArray = new int[GHBblockSize];
 	while(indx<bitsLen)
 	{
 		u32 rl_gamma=0;
 		if(index==bitsLen)
 			break;
 		u32 bits=0;
 		firstBit=getFirstBit(src,index);
 		memset(runsArray,0,GHBblockSize*sizeof(u32));
 		while(bits<GHBblockSize&&index < bitLen)
 		{
 			runs=getRuns(src,index);//还未实现
 			bits=bits+runs;
 			runsArray[k] = runs;
 			k++;
 		}
 		if(bits>GHBblockSize)
 		{//调整位一个确定长度
 			index=index-(bits-GHBblockSize);
 			runsArray[k-1]-=(bits-GHBblockSize);
 		}
 		int i=0;
 		//计算出gamma编码需要的长度
 		for( ; i<k ;i++)
 			rl_gamma+=(getBitsNum(runsArray[i])<<1)+1;

 		//可以建立一定的松弛度,也可以不建立
 		//u32 thred=20;
 		if(k==1)
 		{
 			if(firstBit)
 			{//ALL1存储
 			}
 			else
 			{//ALL0存储
 			}
 		}
 		else if(rl_gamma>GHBblockSize||index==bitsLen)
 		{

 		}
 		else
 		{

 		}


 	}
 	return 0;

}