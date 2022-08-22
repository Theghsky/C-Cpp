#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char** argv)
{
    FILE *rfp,*wfp;
    char buf[20];
    if(argc!=3)
    {
	fprintf(stderr,"Usage: %s <src_filename> <target_filename>\n",argv[0]);
	exit(1);
    }
    if((rfp = fopen(argv[1],"r+")) == NULL){
	perror("fopen");
	exit(1);
    }

    if((wfp = fopen(argv[2],"w")) == NULL){
	perror("fopen");
	exit(1);
    }
    int i=0;
    while((buf[i++]=fgetc(rfp))!=EOF)
    {
    }
    for(i-2;i>=0;i--)
    {
	putchar(buf[i]);
	fputc(buf[i],wfp);
    }

    fclose(rfp);
    fclose(wfp);
    return 0;
}
