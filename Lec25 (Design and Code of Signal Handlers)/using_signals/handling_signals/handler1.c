#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void myhandler(int signum)
{
    printf("\nHey I got a signal : %d\n\n", signum);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, &myhandler);
    while (1)
    {
        printf("I am in an infinite loop\n");
        sleep(1);
    }

    return 0;
}
