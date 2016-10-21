#include<iostream>
using namespace std;
int trade(int bottle)
{
	int n=0;
	if(bottle<2)
	{
		return n;
	}
	else if(bottle==2)
	{
		return n+1;
	}
	n=bottle/3;
	n+=trade(n+bottle%3);
	return n;
}
int main()
{
	int bottle[10]={0};
	int fillBot[10]={0};
	int num=0;
	cin>>bottle[num];
	while(bottle[num]>0&&num<10)
	{
		num++;
		cin>>bottle[num];
	}
	cout<<"num="<<num<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"fillBot["<<i<<"]="<<fillBot[i];
		cout<<"\tbottle["<<i<<"]="<<bottle[i]<<endl;
	}
	for(int i=0;i<num;i++)
	{
		
		fillBot[i]+=trade(bottle[i]);
		cout<<fillBot[i]<<endl;
	}
	return 0;
}