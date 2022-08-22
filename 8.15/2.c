#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int sno;
    char name[20];
    float score;
};

int main(int argc,char **argv)
{
    FILE * fp;
    int i;
    struct student st[3];

    if(argc != 2){
	fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
	exit(1);
    }

    if((fp = fopen(argv[1],"r")) == NULL){
	perror("fopen");
	exit(1);
    }

//从文件中读出数据
    for(i =0; i < 3; i++){
	printf("请输入学生信息:");
	fscanf(fp,"%d%s%f",&st[i].sno,st[i].name,&st[i].score);
	printf("%d %s %.2f\n",st[i].sno,st[i].name,st[i].score);  //将buf输出的结果写到文件中
       }
       return 0;
}
