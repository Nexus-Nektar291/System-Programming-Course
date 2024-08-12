#include <stdio.h>
#include <stdlib.h>

void print1(int arr[], const int size);
void print2(int *ptr, const int size);

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Printing 1D array using array notation.\n");
    print1(arr, 5);
    printf("Printing 1D array using pointer notation.\n");
    print2(arr, 5);

    return 0;
}

void print1(int arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", *(arr + i));
    }
    printf("\n");
}

void print2(int *ptr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", *(ptr + i));
    }
    printf("\n");
}