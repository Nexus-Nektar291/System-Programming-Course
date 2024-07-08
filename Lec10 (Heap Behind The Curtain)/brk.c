#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Before any allocation brk is at   : %p\n", sbrk(0));

    char *a = (char *)malloc(100);
    printf("After first allocation brk is at  : %p\n", sbrk(0));

    char *b = (char *)malloc(100);
    printf("After second allocation brk is at : %p\n", sbrk(0));

    char *c = (char *)malloc(100);
    printf("After third allocation brk is at  : %p\n", sbrk(0));

    char *d = (char *)malloc(100);
    printf("After fourth allocation brk is at : %p\n", sbrk(0));

    printf("a = %p\nb = %p\nc = %p\nd = %p\n", a, b, c, d);

    return 0;
}
