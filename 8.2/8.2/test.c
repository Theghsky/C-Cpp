//#include <stdio.h>
//#include <stdlib.h>
//
//float* fun(float* p1, float* p2, float* m)
//{
//	m = (float*)calloc(1, sizeof(float));
//	*m = *p1 + *p2++;
//	return m;
//}
//
//main()
//{
//	float a[2] = { 1.1,2.2 }, b[2] = { 10.0,20.0 }, * s = a;
//	float* m=fun(a, b, s);   printf("%5.2f\n", *m);
//}

//#include <stdio.h>
//main()
//{
//	union {
//		short i[2];
//		long k;
//		char c[4];
//	}r, * s = &r;
//
//	s->i[0] = 0x39; s->i[1] = 0x38;
//	printf("%x\n", s->c[0]);
//}

#include <stdio.h>
struct st
{
	int x;
	int* y;
}*p;

int dt[4] = { 10,20,30,40 };
struct st aa[4] = { 50,&dt[0],60,&dt[0],60,&dt[0],60,&dt[0] };
main()
{
	p = aa;
	printf("%d\n", ++p->x);
	printf("%d\n", (++p)->x);
	printf("%d\n", ++(*p->y));
}