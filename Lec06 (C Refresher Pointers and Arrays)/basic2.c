#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr = NULL;
    printf("Value of ptr : %p\n", ptr);
    printf("Value of ptr : %d\n", ptr);
    printf("Value of sizeof(ptr) : %ld\n", sizeof(ptr));

    if (ptr)
    {
        printf("ptr does not contains NULL.\n");
    }
    else
        printf("ptr contains NULL.\n");
    printf("Value of *ptr : %d\n", *ptr);
    return 0;
}
