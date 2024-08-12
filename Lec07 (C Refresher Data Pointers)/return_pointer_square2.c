#include <stdio.h>
#include <stdlib.h>

int *square(int n1)
{
    int *result = (int *)malloc(sizeof(int));
    *result = n1 * n1;
    return result;
}
int main(int argc, char const *argv[])
{
    int a = 5;
    int *p = square(a);
    printf("Square of %d is %d\n", a, *p);
    free(p);

    return 0;
}
