#include <stdio.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "kernel.h"


#define IP 192.168.101.62
#define PORT 12345

int main(int argc,char **argv)
{
    //创建socket套接字 TCP
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
    //链表初始化
    pkernel_t head=NULL;

    struct list_head *pos=NULL;
    pkernel_t node=NULL;
    
    kernel_init(&head);
    if(head==NULL){
	printf("初始化失败\n");
	exit(1);
    }
    pkernel_t p=head;
    
    int maxfp,fp;
    fd_set readfds;
    struct sockaddr_in client;
    unsigned int len=sizeof(client);
    char buf[100];
    
    while(1){
	maxfp=socketfp;
	//添加前台 
	FD_SET(socketfp,&readfds);
	
	//遍历链表将技师放入
	p=head;
	pos=NULL;
        list_for_each(pos, &p->list)
	{
	    node = list_entry(pos,typeof(*p),list);
	    FD_SET(node->data,&readfds);
	    if(node->data>maxfp){
		maxfp=node->data;
	    }
	}

	//循环阻塞等待响动
	ret=select(maxfp+1,&readfds,NULL,NULL,NULL);
	if(ret<0){
	    perror("select");
	    exit(1);
	}
	//判断是谁响动  socktfp前台  还是  技师
        //如果是前台将  新的技师 加入 链表
	if(FD_ISSET(socketfp,&readfds)){
	    fp=accept(socketfp,(struct sockaddr*)&client,&len);
	    if(fp<0){
	        perror("accept");
		exit(1);
	    }
	    printf("%d号技师上线了\n",fp);
	    kernel_add_tail(head,fp);
	    continue;
	}
	
	p=head;
	pos=NULL;
	list_for_each(pos, &p->list)
	{
	    node = list_entry(pos,typeof(*p),list);
	    if(FD_ISSET(node->data,&readfds)){
		bzero(buf,sizeof(buf));
		ret=recv(node->data,buf,sizeof(buf),0);
		if(ret>0){
		    printf("骚年-%d号技师说:%s\n",node->data,buf);
		}else{
		    printf("客户逃跑了\n");
		    kernel_del(head,node->data);
		}
		break;
	    }
	}
    }
    close(fp);
    close(socketfp);
    return 0;
}
