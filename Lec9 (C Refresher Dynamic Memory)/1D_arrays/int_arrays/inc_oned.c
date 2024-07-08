#include <stdlib.h>
#include <stdio.h>

int main()
{
    // get size of 1D integer array from user
    int i, size;
    printf("Enter size of array : ");
    scanf("%d", &size);

    // allocate memory for the array on heap
    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
        perror("Malloc Failed\n");

    // get input in the integer array
    printf("Enter %d elements of array : \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display elements of array on stdout
    printf("Elements of array are : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    puts("");

    // Resize the memory in heap using realloc
    int newsize;
    printf("Enter new size of array : ");
    scanf("%d", &newsize);

    int *nptr = (int *)realloc(arr, sizeof(int) * newsize);
    if (nptr == NULL)
    {
        perror("Realloc Failed");
    }
    else
        arr = nptr;

    // Display elements of array on stdout
    printf("The resized array elements are :\n ");
    for (int i = 0; i < newsize; i++)
    {
        printf("%d \t", arr[i]);
    }
    puts("");

    // Free memory on heap when you are done
    free(arr);
}