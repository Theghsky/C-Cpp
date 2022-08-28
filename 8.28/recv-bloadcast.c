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
#define BROADCAST "192.168.101.255"

int main(int argc,char **argv)
{
    //创建 UDP
    int socketfp=socket(AF_INET,SOCK_DGRAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    //绑定 广播地址
    struct sockaddr_in broadcast;
    broadcast.sin_family=AF_INET;
    broadcast.sin_port=htons(PORT);
    broadcast.sin_addr.s_addr=inet_addr(BROADCAST);
    int ret=bind(socketfp,(struct sockaddr*)&broadcast,sizeof(broadcast));
    //接收数据
    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	ret=recvfrom(socketfp,buf,sizeof(buf),0,NULL,NULL);
	if(ret<0){
	    perror("recvfrom");
	    exit(1);
	}
	printf("广播说：%s\n",buf);
    }
    close(socketfp);
    return 0;
}
