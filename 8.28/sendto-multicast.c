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
    //判断是否三个参数
    if(argc!=3){
	printf("%s <IP><PORT>",argv[0]);
	exit(1);
    }
    //设置socket UDP
    int socketfp=socket(AF_INET,SOCK_DGRAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    //设置允许发送组播
    int on=1;
    setsockopt(socketfp,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));
    //组播地址
    struct sockaddr_in other;
    other.sin_family=AF_INET;
    other.sin_port=htons(atoi(argv[2]));
    other.sin_addr.s_addr=inet_addr(argv[1]);
    //发送数据
    char buf[100];
    int ret;
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
