#include <stdio.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "link.h"

#define IP 192.168.101.62
#define PORT 12345

int main(int argc,char** argv)
{   
    //chuangjian Socket
    int socketfp=socket(AF_INET,SOCK_STREAM,0);
    if(socket<0){
	perror("socket");
	exit(1);
    }
    //重用地址
    int on = 1;
    setsockopt(socketfp,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

    //bangding IP PORT
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=INADDR_ANY;
    int ret=bind(socketfp,(struct sockaddr*)&server,sizeof(server));
    if(ret<0){
	perror("bind");
	exit(1);
    }
    //jinating
    ret=listen(socketfp,30);
    if(ret<0){
	perror("listen");
	exit(1);
    }
    //link_t baocun shuju  
    plink_t head=NULL;
    link_init(&head);
    if(head==NULL){
	printf("falus\n");
	exit(1);
    }
    plink_t p=head;
    
    int maxfd,fd;
    fd_set readfds;
    struct sockaddr_in client;
    unsigned int len=sizeof(client);
    char buf[100];

    while(1){
	maxfd=socketfp;
	FD_SET(socketfp,&readfds);

	p=head;
	while(p->next!=head){
	    p=p->next;
	    FD_SET(p->data,&readfds);
	    if(p->data>maxfd){
		maxfd=p->data;
	    }
	}

	ret=select(maxfd+1,&readfds,NULL,NULL,NULL);
	if(ret<0){
	    perror("select");
	    exit(1);
	}
	
	if(FD_ISSET(socketfp,&readfds)){
	    fd=accept(socketfp,(struct sockaddr*)&client,&len);
	    if(fd<0){
		perror("accept");
		exit(1);
	    }
	    link_add_tail(head,fd);
	    continue;
	}

	p=head;
	while(p->next!=head){
	    p=p->next;
	    if(FD_ISSET(fd,&readfds)){
		bzero(buf,sizeof(buf));
		ret=recv(p->data,buf,sizeof(buf),0);
		if(ret>0){
		    printf("骚年-%d号技师说:%s\n",p->data,buf);
		}else{
		    printf("客户逃跑了\n");
		    link_del(head,p->data);
		}
		break;
	    }
	}
    }
    
    close(fd);
    close(socketfp);


    return  0;
}
