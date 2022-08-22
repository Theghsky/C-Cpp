#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include<time.h>
#include <sys/wait.h>
int main(int argc,char **argv)
{
   // pid_t pid;
    int fd;
    char buf[100];
   // time_t tm;
    int ret;
    int nums=atoi(argv[1]);

    if(access(argv[2],F_OK)<0){
	if(mkfifo(argv[2],0666)<0){
	    perror("mkfifo");
    	    exit(1);
	}
    }
    if((fd=open(argv[2],O_RDWR))<0){
	perror("open");
	exit(1);
    }

    printf("管道3打开成功....\n");
        
    while(nums--){
	memset(buf,0,sizeof(buf));
	if((ret=read(fd,buf,sizeof(buf)))<0){
	    perror("read");
	    exit(1);
	}
	printf("%s\n",buf);
    }
    close(fd);
    return 0;
}
