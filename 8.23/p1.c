#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pthread.h>
#include<unistd.h>
#include <semaphore.h>
sem_t sem1,sem2;
int buf[10];

void* fun1(void* arg)
{
    int i;
    printf("请输入字符串\n");
    for(i=0;i<10;i++){
	scanf("%d",&buf[i]);
    }	
    sem_post(&sem1);
    
    pthread_exit(0);
}
void* fun2(void* arg)
{
    int i,j;
    sem_wait(&sem1);
    for(i=0;i<9;i++){
	for(j=0;j<9-i;j++){
	    if(buf[j]<buf[j+1]){
		int temp=buf[j];
		buf[j]=buf[j+1];
		buf[j+1]=temp;
	    }	
	}	    
    }
    printf("排序完成\n");	
    for(i=0;i<10;i++){	
	printf("%d ",buf[i]);
	sleep(1);
    }
    printf("\n");
    sem_post(&sem2);
    pthread_exit(0);
}
void* fun3(void* arg)
{   
    sem_wait(&sem2);
    int i;
    FILE * fp=fopen("1.txt","w");
    for(i=0;i<10;i++){
	fprintf(fp,"%d ",buf[i]);
	fflush(fp);
	printf("%d ",buf[i]);
	fflush(stdout);
    }
    printf("\n");
    
    pthread_exit(0);
}



int main(int argc,char **argv)
{
    pthread_t tid1,tid2,tid3;
    
    sem_init(&sem1,0,0);
    sem_init(&sem2,0,0);

    //创建线程
    if(pthread_create(&tid1,NULL,fun1,NULL)){    
	perror("pthread_create");
	exit(1);
    }
    if(pthread_create(&tid2,NULL,fun2,NULL)){
	perror("pthread_create");
	exit(1);
    }
    if(pthread_create(&tid3,NULL,fun3,NULL)){
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
    if(pthread_join(tid3,NULL)){
	perror("pthread_join");
	exit(1);
    }
    
    pthread_exit(0);
}
