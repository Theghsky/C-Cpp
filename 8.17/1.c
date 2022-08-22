#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(int argc,char **argv)
    {
	printf("euid= %d \n",geteuid());
	return 0;
    }
