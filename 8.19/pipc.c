#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


		int main(int argc,char **argv)
		{
		int fd[2];
		pid_t pid;
		char buf[100];

		//创建无名管道
		if(pipe(fd) < 0){
			perror("pipe");
			exit(1);
		}

		//创建子进程
		if((pid = fork()) < 0){
			perror("fork");
			exit(1);
		}else if(!pid){  //子进程：从键盘获取字符串，写到管道中
			close(fd[0]);
			while(1){
				memset(buf,0,sizeof(buf));
				fgets(buf,sizeof(buf),stdin);
				buf[strlen(buf)-1] = '\0';
				write(fd[1],buf,strlen(buf));
			}

		}else{  //父进程: 从管道读出数据，并打印到屏幕上
			close(fd[1]);
			while(1){
				memset(buf,0,sizeof(buf));
				if(read(fd[0],buf,sizeof(buf)) < 0){
					perror("read");
					exit(1);
				}
				printf("%s\n",buf);
			}
		}

		return 0;
	}
