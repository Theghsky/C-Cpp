#include<stdio.h>

#include<stdlib.h>

int main(int argc,char **argv)
{
    FILE *fp;
    char ch;
    int i;
    
    fp=fopen(argv[1],"r");

    for(i=0;i<4;i++)
    {
	ch=fgetc(fp);
	printf("%c",ch);
    }
    int len;
    fseek(fp,0,SEEK_END);
    len=ftell(fp);
    printf("%ld\n",len);
    return 0;
}
