#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv)
{

	FILE* fp;
	if(argc!=2)
	{
	    fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
	    exit(1);
	}
	if((fp = fopen(argv[1],"w")) == NULL)
	{
	    perror("fopen");
	    exit(1);
	}

	char buf[100];
	while(1)
	{
	    bzero(buf,sizeof(100));
	    scanf("%s",buf);
	    fprintf(fp,"%s\n",buf);
	    fflush(fp);
	}
	return 0;
}
