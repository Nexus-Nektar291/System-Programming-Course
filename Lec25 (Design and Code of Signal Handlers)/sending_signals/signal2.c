#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    while (1)
    {
        printf("I am in an infinite loop! Press <Ctrl+C> to exit. \n");
        sleep(1);
    }
    return 0;
}
