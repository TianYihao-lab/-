#include<stdio.h>

union Object
{
    int a;
    char b;
    float c;
    double d;
};

union Object u;

int main()
{
    u.a = 55;
    printf("%d,%d\n", u.a, u.b); // a、b所使用的其实是一块内存空间，对u.a赋值，u.b也会受到影响
    u.b = 'a';
    printf("%d,%d\n", u.a, u.b);
    printf("%c %c\n", u.a, u.b);

    u.c = 3.14;
    //printf("%d %d %d %d", u.a, u.b, u.c, u.d);
    //printf("%d %c %f \n", u.a, u.b, u.c);

    printf("%u\n", sizeof(union Object)); // 联合体在内存中占用的空间由联合体内所用字长最大的变量决定
    return 0;
}