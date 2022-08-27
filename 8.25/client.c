#include<error.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<pthread.h>

void* readMsg(void *arg)
{   
    int fp=*(int*)arg;
    char buf[100];
    int n=10;
    int ret;
    while(1){
	bzero(buf,sizeof(buf));
	ret=recv(fp,buf,sizeof(buf),0);
	if(ret>0){
	    printf("recv say:%s\n",buf);
	    n=10;
	}else if(ret==0){
	    printf("server quit \n");
	    close(fp);
	    exit(1);
	}else {
	    while(n--)
		continue;
	    close(fp);
	    exit(1);
	}
    }
}

int main(int argc,char** argv)
{
    if(argc!=3){
	printf("usage:%s <ip><port>\n",argv[0]);
	exit(1);
    }

    //创建Socket
    int socketfp=socket(AF_INET,SOCK_STREAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }    
    //link-server
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(atoi(argv[2]));
    server.sin_addr.s_addr=inet_addr(argv[1]);
    int ret=connect(socketfp, (struct sockaddr*)&server,sizeof(server));
    if(ret<0){
	perror("connect");
	exit(1);
    }
 
    //做一个线程相互通信
    pthread_t thread;
    pthread_create(&thread,NULL,readMsg,&socketfp);
    pthread_detach(thread);

    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	scanf("%s",buf);
	send(socketfp,buf,strlen(buf),0);
    }
    
    close(socketfp);

    return 0;
}
