#include <stdio.h>
#include<time.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define perr(str) ({perror(str);exit(1);})

int main(int argc,char **argv)
{
	int fd;
	int n;

	if(argc !=2){
		fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
		exit(1);
	}

	if((fd = open(argv[1],O_WRONLY|O_CREAT,0666)) < 0)
		perr("open");

	printf("请输入文件的大小:");
	scanf("%d",&n);

	//1,设置文件位移量
	lseek(fd,n-3,SEEK_SET);


	//2,写入一个标签
	write(fd,"end",3);


	close(fd);

	return 0;
}
