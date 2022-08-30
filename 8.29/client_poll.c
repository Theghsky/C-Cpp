#include <arpa/inet.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<poll.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
int main(int argc,char **argv)
{
    //判断是否三个参数
    if(argc!=3){
	printf("usage: %s <IP><PORT>\n",argv[1]);
	exit(1);
    }
    //创建c_socket
    int socketfp=socket(AF_INET,SOCK_STREAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    //建立链接
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(atoi(argv[2]));
    server.sin_addr.s_addr=inet_addr(argv[1]);
    int ret=connect(socketfp,(struct sockaddr*)&server,sizeof(server));
    //poll监听
    struct pollfd fds[2];
    fds[0].fd=0;
    fds[0].events=POLLIN;

    fds[1].fd=socketfp;
    fds[1].events=POLLIN;
    char buf[100];
    
    while(1){
    //poll阻塞
	ret=poll(fds,2,1);
	if(ret<0){
	    perror("poll");
	    exit(1);
	}

    //发送接受消息
	if(fds[0].revents==POLLIN){
	    bzero(buf,sizeof(buf));
	    scanf("%s",buf);
	    send(socketfp,buf,sizeof(buf),0);
	    fds[0].revents=0;
	}else if(fds[1].revents==POLLIN){
	    bzero(buf,sizeof(buf));
	    ret=recv(socketfp,buf,sizeof(buf),0);
	    if(ret>0){
		printf("技师说:%s\n",buf);
	    }else{
		printf("技师逃跑了\n");
		close(socketfp);
		exit(-1);
	    }
	    fds[1].revents=0;
	}
    }
    close(socketfp);


    return 0;
}
