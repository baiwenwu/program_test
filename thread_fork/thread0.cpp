/*
*/
# include <unistd.h>
# include <stdio.h>
int main()
{
	pid_t fpid; //fpid表示fork函数的返回值
	int count = 0;
	fpid = fork();
	 if( fpid < 0)
	 {
	 	printf( " error in fork!\n");
	 }
	 else if( 0 ==  fpid )
	 {
	 	printf("son, id=%d\n", getpid() );
	 	count ++;
	 }
	 else
	 {
	 	printf(" parent, id=%d\n", getpid() );
	 	count ++;	 
	 }
	 printf(" count=%d\n",count);
	return 0;
}