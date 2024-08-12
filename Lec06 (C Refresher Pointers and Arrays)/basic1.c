#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 54;
    int *ptr = &i;
    printf("Value of i : %d\n", i);
    printf("Value of &i : %p\n", &i);
    printf("Value of ptr : %p\n", ptr);
    printf("Value of &ptr : %p\n", &ptr);
    printf("Value of *ptr : %d\n", *ptr);
    printf("Value of sizeof(ptr) : %ld\n", sizeof(ptr));
    printf("Value of sizeof(i) : %ld\n", sizeof(i));
    return 0;
}