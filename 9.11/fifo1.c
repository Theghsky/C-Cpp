#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc,char **argv)
{
    int fd;
    char buf[100];

    if(argc != 2){
	fprintf(stderr,"Usage: %s<fifoname>\n",argv[0]);
	exit(1);
    }

    if((access(argv[1],F_OK)<0)){
	if(mkfifo(argv[1],0666)<0){
	    perror("mkfifo");
	    exit(1);
	}
    }

    if((fd=open(argv[1],O_RDWR))<0){
	perror("open");
	exit(1);
    }

    while(1){
	memset(buf,0,sizeof(buf));
	printf("请输入字符串:");
	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf)-1]='\0';
	if(write(fd,buf,strlen(buf))<0){
	    perror("write");
	    exit(1);
	}
	if(!strncmp(buf,"quit",4))
	    break;
    }
    close(fd);
    return 0;
}
