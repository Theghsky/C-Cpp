#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



	int main(int argc,char **argv)
	{
		int fd,newfd;
		char buf[100];



		if((fd = open("1.txt",O_WRONLY|O_CREAT|O_TRUNC,0666)) < 0)
			perr("open");
		if((newfd = open("2.txt",O_WRONLY|O_CREAT|O_TRUNC,0666)) < 0)
			perr("open");
	#if 0
		//将标准输出重定向到文件中
		dup2(fd,STDOUT_FILENO);
		printf("hello world\n");
	#else
		write(fd,"hello",5);
		dup2(fd,newfd);    //把newfd重定向到fd,同时关闭newfd原来的文件
		write(newfd,"world",5);
	#endif
		close(fd);
		close(newfd);

		return 0;
	}
