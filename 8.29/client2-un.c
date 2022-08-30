

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/un.h>


#define MAKE "udp-un2"

void* readMsg(void *arg)
{
    int fp=*(int *)arg;
    char buf[100];
    int ret;
    while(1){
	bzero(buf,sizeof(buf));
	ret=recvfrom(fp,buf,sizeof(buf),0,NULL,NULL);
	if(ret<0){
	    perror("recvfrom");
	    exit(1);
	}
	printf("吊毛说：%s\n",buf);
    }
}


int main(int argc,char **argv)
{
    //判断是否有两个参数
    if(argc!=2){
	printf("%s <MAKE>",argv[0]);
	exit(1);
    }
    
    //删除原有套接字文件
    remove(MAKE);
    
    //创建UDP socket
    int socketfp=socket(AF_UNIX,SOCK_DGRAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    
    //绑定自己的域-套接字文件
    struct sockaddr_un myself;
    myself.sun_family=AF_UNIX;
    strcpy(myself.sun_path,MAKE);
    int ret=bind(socketfp,(struct sockaddr*)&myself,sizeof(myself));
    if(ret<0){
	perror("bind");
	exit(1);
    }
     
    //开线程收数据
    pthread_t thread;
    pthread_create(&thread,NULL,readMsg,&socketfp);
    pthread_detach(thread);

    struct sockaddr_un other;
    other.sun_family=AF_UNIX;
    strcpy(other.sun_path,argv[1]);
    
    //发数据--发去哪里
    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	scanf("%s",buf);
	ret=sendto(socketfp,buf,sizeof(buf),0,(struct sockaddr*)&other,sizeof(other));
	if(ret<0){
	    perror("sendto");
	    exit(1);
	}
    }

    close(socketfp);
    return 0;
}
