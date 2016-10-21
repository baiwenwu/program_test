#include<iostream>
using namespace std;
int bijiao(int x,int y)
{
	if(x>y)
		return 1;
	else if(x==y)
		return 0;
	else
		return -1;
}
void swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
