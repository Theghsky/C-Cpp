#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char **argv)
{
    int fd;
     
    if(access(argv[1],F_OK)<0)
	fd=open(argv[1],O_WRONLY|O_CREAT,0666);
    else
	fd=open(argv[1],O_WRONLY);

    return 0;
}
