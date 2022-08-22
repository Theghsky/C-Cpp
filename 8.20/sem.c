#include "sem.h"

//给单个信号灯初始化
void sem_init(int semid,int semnum,int value)
{
    union semun un;
    un.val = value;
    if(semctl(semid,semnum,SETVAL,un) < 0){
	perror("semctl");
	exit(1);
    }
}
//给所有信号灯初始化
void sem_init_ALL(int semid,int semnum,unsigned short *value)
{
    union semun un;
    un.array = value;
    if(semctl(semid,semnum,SETALL,un) < 0){
	perror("semctl");
	exit(1);
    }
}
//实现p操作
void sem_p(int semid,int semnum)
{
    struct sembuf buf = {semnum,-1,0};

    if(semop(semid,&buf,1) < 0){
	perror("semop");
	exit(1);
    }
}
//实现v操作
void sem_v(int semid,int semnum)
{
    struct sembuf buf = {semnum,1,0};

    if(semop(semid,&buf,1) < 0){
	perror("semop");
	exit(1);
    }
}


