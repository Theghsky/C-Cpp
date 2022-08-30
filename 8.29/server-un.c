#include <stdio.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>


#define MAKE "tcp-un"
int main(int argc,char **argv)
{
    //创建socket TCP
    int socketfp=socket(AF_UNIX,SOCK_STREAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }

    //删除原有套接字文件
    remove(MAKE);

    //绑定套接字文件
    struct sockaddr_un un;
    un.sun_family=AF_UNIX;
    strcpy(un.sun_path,MAKE);
    int ret=bind(socketfp,(struct sockaddr*)&un,sizeof(un));
    if(ret<0){
	perror("bind");
	exit(1);
    }
    //监听
    ret=listen(socketfp,30);
    if(ret<0){
	perror("listen");
	exit(1);
    }

    //阻塞等待客户端
    int fp=accept(socketfp,NULL,NULL);
    if(fp<0){
	perror("accept");
	exit(1);
    }

    //循环接收
    char buf[100];
    int n=10;
    while(1){
	bzero(buf,sizeof(buf));
	ret=recv(fp,buf,sizeof(buf),0);
	if(ret>0){
	    printf("骚年说:%s\n",buf);
	    n = 10;
	}else if(ret==0){
	    printf("客户逃跑了\n");
	    close(fp);
	    break;
	}else{
	    while(n--)
		continue;
	    close(fp);
	    break; 
	}
    }


    close(fp);
    close(socketfp);
    return 0;
}
