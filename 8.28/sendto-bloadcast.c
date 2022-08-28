#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


int main(int argc,char **argv)
{
    if(argc!=3){
	printf("usage: %s <IP><PORT>",argv[0]);
	exit(1);
    }
    //创建 UDP
    int socketfp=socket(AF_INET,SOCK_DGRAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    //设置允许发送
    int on=1;
    setsockopt(socketfp,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));
    //绑定 广播地址
    struct sockaddr_in other;
    other.sin_family=AF_INET;
    other.sin_port=htons(atoi(argv[2]));
    other.sin_addr.s_addr=inet_addr(argv[1]);
    //接收数据
    int ret;
    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	scanf("%s",buf);
	ret=sendto(socketfp,buf,sizeof(buf),0,(struct sockaddr*)&other,sizeof(other));
	if(ret<0){
	    perror("recvfrom");
	    exit(1);
	}
    }
    close(socketfp);
    return 0;
}
