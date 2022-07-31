//#include <stdio.h>
//char* GetMemory(void);
//char* GetMemory(void)
//{
//    char p[] = "hello world";
//    return p;
//}
//int main(void)
//{
//    char* str = NULL;
//    printf(str);
//    return 0;
//}


#include "stdio.h"
int main()
{
    char c;
    int letters = 0, space = 0, digit = 0, others = 0;
    printf("please input some characters\n");
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            letters++;
        else if (c == ' ')
            space++;
        else if (c >= '0' && c <= '9')
            digit++;
        else
            others++;
    }
    printf("all in all:char=%d space=%d digit=%d others=%d\n", letters,space, digit, others);
    return 0;
}
