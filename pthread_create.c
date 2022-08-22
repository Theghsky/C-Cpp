#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void* fun(void *arg)
{   
    int i;
    printf("%d\n",*(int *)arg);
    for(i=0;i<10;i++){
	printf("子线程:%ld\n",pthread_self());
	sleep(1);
    }
    static int a=100;
 //   exit(0);
    pthread_exit(&a);
 //   return &a;
    return 0;
}

int main(int argc,char **argv)
{
    int i;
    pthread_t tid;
    int a=120;
    if(pthread_create(&tid,NULL,fun,&a)){
	perror("pthread_create");
	exit(1);
    }
 //   exit(0); 
//    pthread_exit(0);
    	
 /*   for(int j=0;j<10;j++){
	printf("艹\n");
	sleep(1);
	if(j==5)
	    pthread_cancel(tid);
    }*/

   /* int *p;
    if(pthread_join(tid,(void**)&p)){
	perror("pthread_join");
	exit(1);
    }*/
    if(pthread_join(tid,NULL)){
	perror("pthread_join");
	exit(1);
    }
    
 //   printf("*p:%d\n",*p);
    for(i=0;i<10;i++){
	printf("主线程:%ld\n",pthread_self());
	sleep(1);
    }
  pthread_exit(0);  
    return 0;
}
