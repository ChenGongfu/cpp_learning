#include <stdio.h>

int main ()
{   
    // Q1: double * 访问 int 数据 发生啥？
    int a;
    a = 0xaaaaaaaa;
    printf("a = %d\n", a);

    int * p1;
    p1 = &a;
    printf("p1 = %p\n", p1);
    printf("*p1 = %d\n", *p1);
    printf("bin data *p1 = %08x\n", *p1);
    printf(" sizeof(*p1) = %lu bytes\n", sizeof(*p1));

    double * p2;
    p2 = &a;
    printf("p2 = %p\n", p2);
    printf("*p2 = %d\n", *p2);
    printf("bin data *p2 = %08x\n", *p2);
    printf(" sizeof(*p2) = %lu bytes\n", sizeof(*p2));

}