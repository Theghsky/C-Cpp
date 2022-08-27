#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<pthread.h>

#define IP "192.168.101.62"
#define PORT 12345

struct sockaddr_in client;
void* readMsg(void* arg);

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
	    printf("recv");
	    n=10;
	}else if(ret==0){
	    printf("客户掉线\n");
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
    //创建Socket
    int socketfp=socket(AF_INET,SOCK_STREAM,0);
    if(socketfp<0){
	perror("socket");
	exit(1);
    }

    int on = 1;
    setsockopt(socketfp,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));   
   
    //绑定IP PORT 
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=INADDR_ANY;
//    server.in_addr.s_addr=inet_addr(IP);
    int ret=bind(socketfp,(struct sockaddr*)&server,sizeof(server));
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
    
    //阻塞等待登录
    struct sockaddr_in  client;
    unsigned int len = sizeof(client);
    int fp=accept(socketfp,(struct sockaddr*)&client,&len);
    if(fp<0){
	perror("accept");
	exit(1);
    }
    printf("%d服务器一上线\n",fp);
    printf("客户ip:%s\n",inet_ntoa(client.sin_addr));
    printf("客户PROT：%hu\n",ntohs(client.sin_port));

    //做一个线程相互通信
    pthread_t thread;
    pthread_create(&thread,NULL,readMsg,&fp);
    pthread_detach(thread);

    char buf[100];
    while(1){
	bzero(buf,sizeof(buf));
	scanf("%s",buf);
	send(fp,buf,strlen(buf),0);
    }
    
    close(fp);
    close(socketfp);

    return 0;
}
