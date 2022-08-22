#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SIZE  100
struct msgbuf {
        long mtype;
	char mtext[SIZE];
};




int main(int argc,char **argv)
{
    key_t key1,key2;
    int mag_id1,mag_id2;
    struct msgbuf buf1,buf2;
    pid_t pid;

    if((key1=ftok("./",0xa))<0){
	perror("ftok");
	exit(1);
    }

    if((key2=ftok("./",0xb))<0){
	perror("ftok");
	exit(1);
    }

    if((mag_id1=msgget(key1,IPC_CREAT|0666))<0){
	perror("msgget");
	exit(1);
    }


    if((mag_id2=msgget(key2,IPC_CREAT|0666))<0){
	perror("msgget");
	exit(1);
    }

    if((pid=fork())<0){
	perror("fork");
	exit(1);
    }else if(!pid){
	while(1){//子进程接收
	    memset(&buf2,0,sizeof(buf2));
	    buf2.mtype=100;
	 //   printf("请输入接受的消息类型:");
	 //   scanf("%ld",&buf2.mtype);

	    if(msgrcv(mag_id2,&buf2,SIZE,buf2.mtype,0)<0){
		perror("msgrcv");
		exit(1);
	    }
	    printf("%s(type:%ld)\n",buf2.mtext,buf2.mtype);
	}
    }else{
	while(1){//父进程发送

	    memset(&buf1,0,sizeof(buf1));
	    buf1.mtype=200;
	//    printf("请输入发送的消息类型：");
	//   scanf("%ld",&buf1.mtype);
	    printf("请输入发送的消息:");
	    while(getchar()!='\n');
	    fgets(buf1.mtext,SIZE,stdin);
	    buf1.mtext[strlen(buf1.mtext)-1]='\0';
	    if(msgsnd(mag_id1,&buf1,strlen(buf1.mtext),0)<0){
		perror("msgsnd");
		exit(1);
	    }
	}

    }
    return 0;
}

