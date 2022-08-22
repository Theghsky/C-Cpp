#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <syslog.h>
#include <errno.h>


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

	//打开日志
	openlog("jjj",LOG_PID,LOG_DAEMON);

	if((fp = fopen("1.txt","r")) == NULL){
	//	perror("fopen");
		syslog(LOG_ERR,"fopen:%s\n",strerror(errno));   
		exit(1);
	}
	int i=50;
	while(i--){
		time(&tm);
		sprintf(buf,"%s",ctime(&tm));
		fputs(buf,fp);
		fflush(fp);
		sleep(1);
	}

	closelog();  //关闭系统日志

	return 0;
}
