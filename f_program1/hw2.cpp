#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
//#define rand() 
using namespace std;

void *randNum(int *array,int n)
{
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)
	{
		array[i]=rand()%10000+1;
	}
}
int delSame(int *array,int n)
{
	int num0=0;
	for(int i=0;i<n-1;i++)
	{
		if(array[i]==array[i+1])
		{
			num++;
		}
	}

}
int main(){
	int num=0;
	cin>>num;
	int *array=new int[num];
	memset(array,0,sizeof(int)*num);
	randNum(array,num);
	sort(array+0;array+num);
}