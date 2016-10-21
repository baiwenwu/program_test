
    /* 
     *  fork_test.c 
     *  version 3 
     *  Created on: 2010-5-29 
     *      Author: wangth 
     */  
    #include <unistd.h>  
    #include <stdio.h>  
    #include <iostream>
    using namespace std;

    int main(void)  
    {  
       int i=0;  
       for(i=0;i<3;i++){  
           pid_t fpid=fork();  
           if(fpid==0)  
               //printf("son\n");  
           	cout<<"son"<<endl;
           else  
               //printf("father\n");  
           	cout<<"father"<<endl;
       }  
       return 0;  
      
    }  

 