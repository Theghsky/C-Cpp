#include "shm.h"
#include "sem.h"

int main(int argc,char **argv)
{
    key_t key;
    int shm_id,sem_id;
    int *buf;
    int i,j;

    //获取key值
    if((key = ftok("./",0xb)) < 0){
	perror("ftok");
	exit(1);
    }
    //申请共享内存
    if((shm_id = shmget(key,SIZE,IPC_CREAT|0666)) < 0){
	perror("shmget");
	exit(1);
    }

    //创建或获取信号灯
    if((sem_id = semget(key,2,IPC_CREAT|0666))<0){
	perror("semset");
	exit(1);
    }
    //初始化信号灯
    unsigned short arr[2]={0,0};
    sem_init_ALL(sem_id,0,arr);

    //将共享内存映射到进程的虚拟空间
    if((buf = (int *)shmat(shm_id,NULL,0)) < 0){
	perror("shmat");
	exit(1);
    }

    //执行p操作,使进程阻塞，直到v操作唤醒
    sem_p(sem_id,0);

    for(i=0;i<9;i++){
	for(j=0;j<9-i;j++){
	    if(buf[j]<buf[j+1]){
		int tmp=buf[j];
		buf[j]=buf[j+1];
		buf[j+1]=tmp;
	    }
	}
    }
    sem_v(sem_id,1);

    if(shmdt(buf) < 0 ){
	perror("shmdt");
	exit(1);
    }

    return 0;
}

