#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>

int main(void)
{
    pid_t pid;
    int i,n=5;
    for(i=0;i<n;i++){
	if((pid=fork())<0){
	    perror("fork:");
	    exit(-1);
	}else if(pid>0){
	    break;
	}
    }
    for(i=0;i<n;i++)
	wait(NULL);
    printf("%d %d\n",getpid(),getppid());
    return 0;
}
