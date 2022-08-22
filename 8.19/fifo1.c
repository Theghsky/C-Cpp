#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
    int fd1,fd2;
    char buf1[100],buf2[100];
    int ret;
    pid_t pid;

    if(argc!=3){
	fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
	exit(1);
    }

    //如果管道1不存在， 则创建
    if(access(argv[1],F_OK) < 0){
    	if(mkfifo(argv[1],0666) < 0){
    	    perror("mkfifo");
    	    exit(1);
	}
     }
	
     if((fd1 = open(argv[1],O_RDWR)) < 0){
	    perror("open");
	    exit(1);
       }
         printf("管道1打开成功..\n");

    //如果管道2不存在， 则创建
    if(access(argv[2],F_OK) < 0){
       	if(mkfifo(argv[2],0666) < 0){
       	    perror("mkfifo");
       	    exit(1);
       	}
    }	

     if((fd2 = open(argv[2],O_RDWR)) < 0){
	    perror("open");
	    exit(1);
       }
     printf("管道2打开成功..\n");
    
    if((pid=fork())<0){
	perror("fork");
	exit(1);
    }else if(!pid){
	while(1){
	    memset(buf2,0,sizeof(buf2));
	    if((ret=read(fd2,buf2,sizeof(buf2)))<0){
		perror("read");
		exit(1);
	    }
	    if(!strncmp(buf2,"quit",4))
		break;
	    printf("%s\n",buf2);
	}
	close(fd2);
    }else{
	while(1){
	    memset(buf1,0,sizeof(buf1)); 
	    printf("请输入字符串：");
	    fgets(buf1,sizeof(buf1),stdin);
    	    buf1[strlen(buf1)-1] = '\0';
	    if(write(fd1,buf1,strlen(buf1)) < 0){
	        perror("write");
		exit(1);
	    }
	    if(!strncmp(buf1,"quit",4))
		break;
	}

	close(fd1);
    }
    return 0;   
}
