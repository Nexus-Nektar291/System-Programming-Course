#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define TOTAL 5

void myhandler(int signum)
{
    static int count = 0;
    count++;
    printf("\nDon't do it again\n");
    fflush(stdout);
    if (count >= TOTAL)
    {
        printf("Well, if you insist, do it again and i will die!\n");
        fflush(stdout);
        signal(SIGINT, SIG_DFL);
    }
}

int main(int argc, char const *argv[])
{

    signal(SIGINT, myhandler);
    printf("You can't kill me by clicking <CTRL+C>.\n");
    while (1)
        ;
    return 0;
}
