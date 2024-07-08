#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("After five seconds, I will get a SIGHUP signal.\n");
    sleep(5);
    kill(getpid(), 1);
    printf("This line will not be printed.\n");
    return 0;
}
