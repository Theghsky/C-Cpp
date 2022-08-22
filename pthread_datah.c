#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* fun(void * arc)
{
    int i;
    for(i=0;i<10;i++){
	printf("子线程id:%ld\n",pthread_self());
	sleep(1);
    }
    pthread_exit(0);
}

int main(int argc,char** argv)
{
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    
    if(pthread_create(&tid,&attr,fun,NULL)){
	perror("pthread_create");
	exit(1);
    }

  /*  if(pthread_detach(tid)){
	perror("pthread_datach");
	exit(1);
    }*/

   
    printf("主线程id:%ld\n",pthread_self());
    pthread_exit(0);

  //  return 0;
}
