#include <stdio.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>


#define PORT  12345
#define IP    "192.168.101.5"	

struct sockaddr_in client;

void readMsg(int fd)
{
    char buf[100];
    int n=10;
    int ret;
    while(1){
	bzero(buf,sizeof(buf));
	ret=recv(fd,buf,sizeof(buf),0);
	if(ret>0){
	    printf("client<ip:%s>:%s\n",inet_ntoa(client.sin_addr),buf);
	    n=10;
	}else if(ret==0){
	    printf("client run\n");
	    close(fd);
	    exit(1);
	}else{
	    while(n--)
		continue;
	    close(fd);
	    exit(1);
	}
    }
}

int main(void)
{
    //创建socket套接字 
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
	perror("socket error");
	exit(-1);
    }

    //重用地址
    int on = 1;
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

    //绑定IP和PORT
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY; //自动获取到IP
    //  server.sin_addr.s_addr = inet_addr(IP);
    //inet_aton(IP,&server.sin_addr);
    int ret = bind(sockfd,(struct sockaddr *)&server,sizeof(server));
    if(ret){
	perror("bind error");
	exit(-1);
    }

    //监听，将主动连接变成被动连接
    ret = listen(sockfd,30);
    if(ret){
	perror("listen error");
	exit(-1);
    }

    //阻塞等待客户端的连接
    unsigned int len = sizeof(client);
    int fd;
    pid_t pid;
    while(1){
	fd = accept(sockfd,(struct sockaddr *)&client,&len);
	if(fd<0){
	    perror("accept error");
	    exit(-1);
	}

	pid = fork();
	if(pid==0){
	    readMsg(fd);
	    exit(0);
	}

	while(!wait(NULL));

    }

    close(fd);
    close(sockfd);


    return 0;
}
