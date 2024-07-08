#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("I am a running process\n");
    sleep(1);
    printf("I am going to divide a number with zero\n");
    sleep(1);

    int a = 3, b = 3;
    float ans = 54 / (a - b);
    return 0;
}
