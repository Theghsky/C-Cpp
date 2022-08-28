#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 12345
#define MULTICAST "234.234.234.234"

int main(int argc,char **argv)
{
    //创建 socket UDP
    int socketfp=socket(AF_INET,SOCK_DGRAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }
    //绑定 组播 地址
    struct sockaddr_in multicast;
    multicast.sin_family=AF_INET;
    multicast.sin_port=htons(PORT);
    multicast.sin_addr.s_addr=inet_addr(MULTICAST);
    int ret=bind(socketfp,(struct sockaddr*)&multicast,sizeof(multicast));
    if(ret<0){
	perror("bind");
	exit(1);
    }
    //添加自己IP
    struct ip_mreq si;
    si.imr_interface.s_addr=INADDR_ANY;
    si.imr_multiaddr.s_addr=inet_addr(MULTICAST);
    setsockopt(socketfp,IPPROTO_IP,IP_ADD_MEMBERSHIP,&si,sizeof(si));
    //循环接收
    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	ret=recvfrom(socketfp,buf,sizeof(buf),0,NULL,NULL);
	if(ret<0){
	    perror("recvfrom");
	    exit(1);
	}
	printf("组播说：%s\n",buf);
    }
    close(socketfp);
    return 0;
}
