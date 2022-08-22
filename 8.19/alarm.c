#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
    alarm(7);
    alarm(4);
    while(1){
	sleep(1);
	printf("aaaa\n");
    }
    return 0;
}
