#include "global.h"

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

int main()
{
	uchar *src;
	uchar *cdata;
	uchar
}
