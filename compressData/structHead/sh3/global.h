# pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char uchar;

static u32 blockSize=256;
void printBitsOfByte(uchar ch);
void randCreateUcharArr(uchar *arr,u32 len);


