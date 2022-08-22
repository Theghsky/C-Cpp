#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>

void daemon_init(void)
{
    pid_t pid;

    //1，创建子进程
    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid > 0)
	exit(0);
    //2，创建新会话
    if(setsid() < 0){
	perror("setsid");
	exit(1);
    }
    //3，创建子进程
    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid > 0)
	exit(0);

    //4，关闭所有的文件描述符
    int i,max_fd = sysconf(_SC_OPEN_MAX);
    for (i = 0; i < max_fd;i++)
	close(i);

    //5，消除umask影响
    umask(0);

    //6，设置守护进程的工作目录
    chdir("/");

    //7，将标准输入，标准输出，标准错误重定向到/dev/null
    open("/dev/null",O_RDWR);
    dup(0);
    dup(0);

    /******************daemon craete OK*************************/
}

int main(int argc,char **argv)
{
    //让守护进程每隔一秒钟向文件中写一条时间信息
    FILE *fp;
    time_t tm;
    char buf[100];

    daemon_init();  //初始化守护进程

    if((fp = fopen("1.txt","a")) == NULL){
	perror("fopen");
	exit(1);
    }

    while(1){
	time(&tm);
	sprintf(buf,"%s",ctime(&tm));
	fputs(buf,fp);
	fflush(fp);
	sleep(1);
    }

    return 0;
}



