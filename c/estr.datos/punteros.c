#include <stdio.h>

int main()
{
    int a, b, c;
    int *p1, *p2;
    void *p;

    p1 = &a;
    *p1 = 1;

    p2 = &b;
    *p2 = 2;

    p1 = p2;
    *p1 = 0;

    p2 = &c;
    *p2 = 3;

    printf("%d %d %d\n", a, b, c); // 1 0 3

    p = &p1;
    *(int *)p = p2;
    *p1 = 1;

    printf("%d %d %d\n", a, b, c);

	return 0;
}