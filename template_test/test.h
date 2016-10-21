#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

template<typename T>
void swap1(T &a,T &b){
	T tmp=a;
	a=b;
	b=tmp;
};
//void swap(int &a,int &b);