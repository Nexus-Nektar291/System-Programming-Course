#include <stdio.h>
#include <stdlib.h>

void print1(int arr[][3], const int rows);
void print2(int (*arr)[3], const int rows);
void print3(int *arr, const int rows, const int cols);
int main(int argc, char const *argv[])
{
    int arr[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printf("Passing 2D array using array notation.\n");
    print1(arr, 4);
    printf("\nPassing 2D array using pointer to an array notation.\n");
    print2(arr, 4);
    printf("\nPassing 2D array using pointer to int.\n");
    print3(&arr[0][0], 4, 3);

    return 0;
}

void print1(int arr[][3], const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}

void print2(int (*arr)[3], const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void print3(int *arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d \t", *(arr + i * cols + j));
        }
        printf("\n");
    }
}