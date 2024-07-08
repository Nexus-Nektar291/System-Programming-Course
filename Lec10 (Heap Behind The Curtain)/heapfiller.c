#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MB 1024 * 1024

int main()
{
    char *ptr = NULL;
    int ctr = 0;
    while (1)
    {
        ptr = (char *)malloc(MB);                      // Allocate 1 MB of memory
        //memset(ptr, '\0', MB);                         // Set all bytes in the allocated memory to 0
        printf("Currently allocating %d MB\n", ++ctr); // Print the current allocation count
    }
    exit(0);
}
