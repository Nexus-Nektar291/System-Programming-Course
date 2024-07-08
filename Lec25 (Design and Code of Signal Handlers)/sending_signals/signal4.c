#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    __pid_t cpid = fork();
    if (cpid == 0)
    {
        while (1)
        {
            printf("I am child in an infinite loop.\n");
            sleep(1);
        }
    }

    else
    {
        sleep(5);
        kill(cpid, SIGSEGV);
        printf("I have killed my child... Bye\n");
        exit(0);
    }
    return 0;
}
