#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int i = alarm(205);
    printf("i contains : %d\n", i);
    sleep(5);
    int j = alarm(10);
    printf("After alarm(10), j contains : %d\n", j);
    sleep(100);

    return 0;
}
