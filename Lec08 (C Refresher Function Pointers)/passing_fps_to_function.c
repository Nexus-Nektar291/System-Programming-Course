#include <stdio.h>
#include <stdlib.h>

int sum(int, int);
int sub(int, int);
int mul(int, int);
int compute(int (*fptr)(int, int), int, int);

int main(int argc, char const *argv[])
{
    int x = 5, y = 43;

    int rv1 = compute(&sum, x, y);
    printf("%d + %d = %d\n", x, y, rv1);

    int rv2 = compute(&sub, x, y);
    printf("%d - %d = %d\n", x, y, rv2);

    int rv3 = compute(&mul, x, y);
    printf("%d * %d = %d\n", x, y, rv3);

    return 0;
}

int compute(int (*fptr)(int, int), int a, int b)
{
    return (*fptr)(a, b);
}
int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}
