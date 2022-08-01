#include <stdio.h>

int a = 5;

void other(void)
{
    int b = 3;
    static int c = 2;
    a += 5;
    b += 5;
    c += 5;
    printf("%d, %d, %d\n", a, b, c);
    c = b;
}
