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
    int ret;

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
	if(ret=read(fd,buf,sizeof(buf))<0){
	    perror("read");
	    exit(1);
	}
	if(!strncmp(buf,"quit",4))
	    break;
	printf("%s\n",buf);
    }
    close(fd);
    return 0;
}
