#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char **argv)
{
    FILE * fp;
    char ch;
    int i;

    if(argc != 2){
        fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
	exit(1);
    }

    if((fp = fopen(argv[1],"r")) == NULL){
	perror("fopen");
	exit(1);
    }
    for(i = 0; i < 7; i++){
	ch = fgetc(fp);
	printf("%c",ch);
	}
    printf("\n%ld\n",ftell(fp));//
    return 0;
}
