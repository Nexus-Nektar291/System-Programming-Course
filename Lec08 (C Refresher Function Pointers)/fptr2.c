#include <stdio.h>
#include <stdlib.h>

int sum(int num1, int num2)
{
    return (num1 + num2);
}

int main(int argc, char const *argv[])
{
    int x = 10, y = 15;
    int (*fptr)(int, int) = NULL;
    fptr = &sum;
    int rv = (*fptr)(x, y);
    printf("Sum of %d and %d is equals to : %d\n", x, y, rv);

    return 0;
}
