#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void create_daemon();

int main()
{
    create_daemon();
    while (1)
        ;
}

void create_daemon()
{
    // STEP-I : MAKE THE PROCESS CHILD OF SYSTEMD
    pid_t cpid = fork();
    if (cpid > 0)
    {
        exit(0);
    }

    // STEP-II : CLOSE ALL FILE DESCRIPTORS
    struct rlimit r;
    getrlimit(RLIMIT_NOFILE, &r);
    for (int i = 3; i < r.rlim_max; i++)
    {
        close(i);
    }

    // STEP-III : ONLY A SINGLE INSTANCE OF DAEMON PROCESS SHOULD RUN
    int fd = open("f1.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("Open Failed");
    }
    struct flock lock;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;

    int rv = fcntl(fd, F_SETLK, &lock);
    if (rv == -1)
    {
        printf("This process is already running");
        close(fd);
        exit(1);
    }
    fprintf(stderr, "Daemon has started running with PID = %d\n", getpid());

    // STEP-IV : MAKE STANDARD DESCRIPTORS POINT TO /DEV/NULL
    int fd0 = open("/dev/null", O_RDWR);
    dup2(fd0, 1);
    dup2(fd0, 2);

    // STEP-V : MAKE THE DAEMON SESSION LEADER
    setsid();

    // STEP-VI : SET UMASK TO 0 AND ITS PWD TO '/'
    umask(0);
    chdir("/");

    // STEP-VII : IGNORE THE SIGHUP SIGNAL
    signal(SIGHUP, SIG_IGN);
}