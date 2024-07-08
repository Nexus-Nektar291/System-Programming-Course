#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    sigset_t newset, oldset;
    sigemptyset(&newset);
    sigaddset(&newset, SIGINT);
    sigprocmask(SIG_SETMASK, &newset, &oldset);

    for (size_t i = 0; i < 10; i++)
    {
        printf("I am masking SIGINT for 10 seconds\n");
        sleep(1);
    }

    sigprocmask(SIG_SETMASK, &oldset, NULL);
    for (int i = 0; i < 10; i++)
    {
        printf("Now i am having the old sigset without any masking\n");
        sleep(1);
    }

    return 0;
}
