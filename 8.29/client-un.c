#include <stdio.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>



int main(int argc,char **argv)
{
    //判断是否有两个参数
    if(argc!=2){
	printf("%s <MAKE>",argv[0]);
    }

    //创建socket TCP
    int socketfp=socket(AF_UNIX,SOCK_STREAM,0);
    if(socketfp<0){
	perror("socket");
    }
    //连接服务器
    struct sockaddr_un server;
    server.sun_family=AF_UNIX;
    strcpy(server.sun_path,argv[1]);
    int ret=connect(socketfp,(struct sockaddr*)&server,sizeof(server));
    if(ret<0){
	perror("connect");
	exit(1);
    }
    //循环发送
    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	scanf("%s",buf);
	ret=send(socketfp,buf,sizeof(buf),0);
	if(ret<0){
	    perror("sendto");
	    exit(1);
	}
    }
    close(socketfp);
    return 0;
}
