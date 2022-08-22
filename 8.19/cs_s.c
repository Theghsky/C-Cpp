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
    pid_t pid;
    int fd;
    char buf[100];
    time_t tm;
    int nums=atoi(argv[1]);

    if(access(argv[2],F_OK)<0){
	if(mkfifo(argv[2],0666)<0){
	    perror("mkfifo");
    	    exit(1);
	}
    }

    printf("管道3打开成功....\n");
        
    while(nums--){
	if((pid=fork())<0){
	    perror("fork");
	    exit(1);
	}else if(!pid){   
	    if((fd=open(argv[2],O_RDWR))<0){
		perror("open");
		exit(1);
	    }
	    memset(buf,0,sizeof(buf));
	    time(&tm);
	    sprintf(buf,"pid；%d time: %s ",getpid(),ctime(&tm));
	  //  fgets(buf,sizeof(buf),stdout);
	  //  buf[strlen(buf)-1]='\0';
	    if(write(fd,buf,strlen(buf))<0){
		perror("write");
		exit(1);
	    }

	    close(fd);
	    exit(0);
	}else{
	    sleep(1);
	    wait(NULL);
	    continue;
	}
    }
    return 0;
}
