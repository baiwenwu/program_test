# pragma once
#include "baseLib.h"
#include "global.h"

struct bitArray{
	uchar * arr;
	u32 bitLen;
	u32 arrLen;
	u32 setBits;
	//u32 word;
	//uchar offset;
	bitArray(u32 num,u32 bits);
	int writeValue(u32 index);
	int qWriteValue();
	u32 getValue();
};