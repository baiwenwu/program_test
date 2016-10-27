#include "bitsArray.h"

bitArray::bitArray(u32 num,u32 bits)
{
	u32 arrBits=num*bits;
	arrLen=(arrBits>>3)+2;
	arr=(uchar*)malloc(arrLen*sizeof(uchar));
	if(!arr)
	{
		printf("开怕空间失败!\n");
	}
	setBits=bits;
	bitLen=0;
}
int bitArray::writeValue(u16 type)
{
	if(!arr)
	{
		printf("write type to headArray error!\n");
		return -1;
	}
	u32 words = bitLen>>setBits;
	u32 offset = bitLen&7u;
	u16 tmp = arr[words];
	tmp=tmp<<8;
	tmp=(tmp>> ( 16 - setBits - offset) )+type;
	tmp=tmp<<(16 - setBits - offset);
	arr[words++]=( tmp >> 8) & 0xff;
	arr[words] = tmp & 0xff;
	bitLen+=setBits;
	num++;
	return 0;
}
int bitArray::getValue()
{
	u32 index = i*bits ;
	u32 words = index>>3;
	u32 offset = index &7;
	u16 tmp = arr[words++];
	tmp = tmp << 8;
	tmp +=arr[words];
	return ( tmp >> (16- bits - offset))&7;
}
