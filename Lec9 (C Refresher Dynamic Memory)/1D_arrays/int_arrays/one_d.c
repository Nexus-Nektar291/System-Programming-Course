#include <stdio.h>
#include <stdlib.h>

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

    // variables created on heap are implicitly initialized with 0
    printf("The initial values in the arrays are : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");

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
        printf("%d ", arr[i]);
    }
    puts("");

    // Free memory on heap when you are done
    free(arr);
}