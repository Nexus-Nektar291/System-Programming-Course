#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

extern int errno;

int main()
{
    // GET THE NICE VALUE OF CALLING PROCESS
    int nv = getpriority(PRIO_PROCESS, 0);
    printf("Nice value of calling process = %d\n", nv);

    // GET THE NICE VALUE OF ANOTHER PROCESS (PARENT PROCESS)
    nv = getpriority(PRIO_PROCESS, getppid());
    printf("Nice value of parent process = %d\n", nv);

    // GET THE MAXIMUM NICE VALUE OF PROCESS GROUP OF CALLING PROCESS
    nv = getpriority(PRIO_PGRP, 0);
    printf("Maximum priority in calling process group = %d\n", nv);

    // GET THE MAXIMUM NICE VALUE OF USER GROUP OF CALLING PROCESS
    nv = getpriority(PRIO_USER, 0);
    printf("Maximum priority in calling user group = %d\n", nv);

    // CHANGE THE NICE VALUE OF CALLING PROCESS
    errno = 0;
    nv = setpriority(PRIO_PROCESS, 0, -2);
    if (nv == -1 && errno != 0)
    {
        perror("setpriority(PRIO_PROCESS,0,-2) Failed");
        exit(1);
    }

    nv = getpriority(PRIO_PROCESS, 0);
    printf("Nice value after setpriority(PRIO_PROCESS,0,-2) = %d\n", nv);
    return 0;
}
