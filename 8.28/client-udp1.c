#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define PORT 12345

void* readMsg(void *arg)
{
    int fp=*(int*)arg;
    char buf[100];
    int ret;
    while(1){
	bzero(buf,sizeof(buf));
	ret=recvfrom(fp,buf,sizeof(buf),0,NULL,NULL);
	if(ret>0){
	    printf("吊毛说：%s\n",buf);
	}else{
	    perror("recvfrom");
	    exit(-1);
	}
    }
}

int main(int argc,char **argv)
{
    //判断是否输入三个参数
    if(argc!=3){
	printf("usage: %s <IP><PORT>",argv[0]);
	exit(1);
    }
    //创建 UDP socket
    int socketfp=socket(AF_INET,SOCK_DGRAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    //绑定IP PORT
    struct sockaddr_in myself;
    myself.sin_family=AF_INET;
    myself.sin_port=htons(PORT);
    myself.sin_addr.s_addr=INADDR_ANY;
    int ret=bind(socketfp,(struct sockaddr*)&myself,sizeof(myself));
    if(ret<0){
	perror("bind");
	exit(1);
    }
    //开线程收数据
    pthread_t thread;
    pthread_create(&thread,NULL,readMsg,&socketfp);
    pthread_detach(thread);

    struct sockaddr_in other;
    other.sin_family=AF_INET;
    other.sin_port=htons(atoi(argv[2]));
    other.sin_addr.s_addr=inet_addr(argv[1]);
    
    char buf[100];
    //发数据
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
