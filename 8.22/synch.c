#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include <semaphore.h>
sem_t sem;
char buf[100];

void* fun1(void* arg)
{
    while(1){
	printf("请输入字符串\n");
	fgets(buf,sizeof(buf),stdin);
	sem_post(&sem);
    }
    
    pthread_exit(0);
}
void* fun2(void* arg)
{
    while(1){
	sem_wait(&sem);
	printf("%s\n",buf);
	sleep(1);
    }
    
    pthread_exit(0);
}




int main(int argc,char **argv)
{
    pthread_t tid1,tid2;
    
    sem_init(&sem,0,0);

    //创建线程
    if(pthread_create(&tid1,NULL,fun1,NULL)){    
	perror("pthread_create");
	exit(1);
    }
    if(pthread_create(&tid2,NULL,fun2,NULL)){
	perror("pthread_create");
	exit(1);
    }

    if(pthread_join(tid1,NULL)){
	perror("pthread_join");
	exit(1);
    }
    if(pthread_join(tid2,NULL)){
	perror("pthread_join");
	exit(1);
    }
    
    pthread_exit(0);
}
