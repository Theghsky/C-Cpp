#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
    FILE *rfe,*wfe;
    char arr[10];
    char buf[100];
    if(argc!=3){
	fprintf(stderr,"usage: %s  <rfilename> <wfilename>",argv[0]);
	exit(1);
    }
    if((rfe=fopen(argv[1],"r"))==NULL){
	perror("fopen");
	exit(1);
    }
    
    scanf("%s",arr);
    fprintf(rfe,"%s\n",arr);
    fflush(rfe);

    if((wfe=fopen(argv[2],"w"))==NULL){
	perror("fopen");
	exit(1);
    }
    
    while(fgets(buf,sizeof(buf),rfe))
    {
	printf("%s",buf);
        fputs(buf,wfe);	
	fflush(rfe);
    }


    fclose(rfe);
    fclose(wfe);

    return 0;
}
