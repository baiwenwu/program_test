#include "test.h"
void sleepX()
{
	int x=0;
	for(int i=0;i<1000000;i++)
	{
		for(int j=0;j<100;j++)
			x += i-500000;
	}
	cout<<"           \n"<<x<<endl;
}
int main()
{
	clock_t start, finish; 
	double duration;   
	start = clock(); 

	for(int i=0;i<10;i++)
	{

		sleepX();
		finish = clock();
		cout<<"start="<<start<<"\tfinish="<<finish<<endl;  
		duration = (double)(finish - start) / CLOCKS_PER_SEC; 
		//printf( "%f seconds/n", duration );  
		cout<< duration<<" seconds"<<endl;
	}
	// int x=1,y=100;
	// cout<<"before the swap:"<<endl;
	// cout<<"\tx="<<x<<"\ty="<<y<<endl;
	// swap1(x,y);
	// cout<<"after the swap:"<<endl;
	// cout<<"\tx="<<x<<"\ty="<<y<<endl;
	return 0;
}