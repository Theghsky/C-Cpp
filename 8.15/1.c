#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char **argv)
{
    FILE * fp;

		if(argc != 2){
				    fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
						    exit(1);
								}

			    if((fp = fopen(argv[1],"w")) == NULL){
						perror("fopen");
								exit(1);
									    }
    fprintf(fp,"%s\n","hello world");
    fprintf(fp,"%d\n",120);
    fprintf(fp,"%f\n",545.34534);
    return 0;
}
