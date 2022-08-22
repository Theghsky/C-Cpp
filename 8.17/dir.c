#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>


#define perr(str) ({perror(str); exit(1);})
void fun(char *path,char *name);

int main(int argc,char **argv)
{
    DIR * p;
    struct dirent *dp;
    char dirpath[100];
    struct stat st;
    
    if(argc==1){
	strcpy(dirpath,".");
    }else if(argc==2){
	if(lstat(argv[1],&st)<0)
	    perr("lstat");

	if(S_ISREG(st.st_mode)){
	    fun(".",argv[1]);
	    exit(0);
	}else if(S_ISDIR(st.st_mode))
	    strcpy(dirpath,argv[1]);
    }

    //打开目录
    if((p = opendir(argv[1])) == NULL)
	perr("opendir");

    //显示目录中所有文件信息
    while((dp = readdir(p))){
	if(dp->d_name[0]!='.')
	    fun(dirpath,dp->d_name);
    }

    return 0;
}

void fun(char *path,char* name)
{
       struct stat st;
    char pathname[100];
    
    sprintf(pathname,"%s/%s",path,name);
    if(lstat(pathname,&st) < 0)
        perr("lstat");

    //显示文件属性

    //显示文件类型
    if(S_ISREG(st.st_mode))
        printf("-");
    else if(S_ISDIR(st.st_mode))
        printf("d");
    else if(S_ISCHR(st.st_mode))
        printf("c");
    else if(S_ISBLK(st.st_mode))
        printf("b");
    else if(S_ISFIFO(st.st_mode))
        printf("p");
    else if(S_ISSOCK(st.st_mode))
        printf("s");
    else if(S_ISLNK(st.st_mode))
        printf("l");

        //显示文件权限
    int i;
    char str[] = "xwr";
    for(i = 8; i>=0; i--){
        if(st.st_mode & 1<<i)
            printf("%c",str[i%3]);
        else
            printf("-");
    }

    printf(" %lu ",st.st_nlink);

    //显示文件拥有者和所属组
    printf("%s ",getpwuid(st.st_uid)->pw_name);
    printf("%s ",getgrgid(st.st_gid)->gr_name);

    printf("%ld ",st.st_size);
    //文件修改的最后时间和日期
    struct tm *tmp;
    tmp = localtime(&st.st_mtime);
    char *month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    printf("%s %02d %02d:%02d ",month[tmp->tm_mon],tmp->tm_mday,tmp->tm_hour,tmp->tm_min);

    printf("%s\n",name);
    
}
