
#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char **argv)
{
    int fd[2];
    pid_t pid;
    
    //创建管道
    if(pipe(fd)<0){
	perror("pipe");
	exit(1);
    }

    //创建子进程
    if((pid=fork())<0){
	perror("fork:");
	exit(1);	
    }else if(!pid){
	close(fd[0]);
	dup2(fd[1],STDOUT_FILENO);
	execlp("ls","ls","-l",NULL);
    }else{
	close(fd[1]);
	dup2(fd[0],STDIN_FILENO);
	execlp("grep","grep",argv[1],NULL);
    }

    return 0;
}

