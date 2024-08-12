#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int matrix[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printf("Value of matrix         : %p\n", matrix);
    printf("Value of *matrix        : %p\n", *matrix);
    printf("Value of **matrix       : %d\n", **matrix);
    printf("Value of matrix + 1     : %p\n", matrix + 1);
    printf("Value of *(matrix + 1)  : %p\n", *(matrix + 1));
    printf("Value of **(matrix + 1) : %d\n\n", **(matrix + 1));

    printf("Value of sizeof(matrix)   : %ld\n", sizeof(matrix));
    printf("Value of sizeof(*matrix)  : %ld\n", sizeof(*matrix));
    printf("Value of sizeof(**matrix) : %ld\n", sizeof(**matrix));
    return 0;
}