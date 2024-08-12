#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int matrix[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // USING ARRAY NAME AND SUBSCRIPT
    printf("Using array name and subscript: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    // USING ARRAY NAME AND POINTER ARITHMATIC
    printf("\nUsing array name and pointer arithmetic: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    // USING POINTER TO ARRAY
    printf("\nUsing pointer to array: \n");
    int(*ptr1)[3] = matrix;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", ptr1[i][j]);
        }
        printf("\n");
    }

    // USING ARRAY OF POINTERS
    printf("\nUsing array of pointers: \n");
    int *ptr2[4] = {matrix[0], matrix[1], matrix[2], matrix[3]};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", ptr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
