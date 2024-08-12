#include <stdio.h>
#include <stdlib.h>

void square(int n1, int *result)
{
    *result = n1 * n1;
}
int main(int argc, char const *argv[])
{
    int num = 5;
    int rv;
    square(num, &rv);
    printf("The square of %d is %d\n", num, rv);
    return 0;
}
