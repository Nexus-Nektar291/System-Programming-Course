#include <stdio.h>
#include <stdlib.h>

void function(int a)
{
    printf("Value of a is : %d\n", a);
}

int main(int argc, char const *argv[])
{
    void (*fptr)(int) = NULL;
    fptr = &function;
    (*fptr)(54);
    
    return 0;
}
