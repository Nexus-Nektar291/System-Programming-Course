#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    struct sigaction newact;
    newact.sa_handler = SIG_IGN;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);
    sigaction(SIGINT, &newact, NULL);
    sigaction(SIGFPE, &newact, NULL);

    while (1)
    {
        printf("I am in an infinite loop you can't kill using SIGNINT or SIGFPE.\n");
        sleep(2);
    }

    return 0;
}
