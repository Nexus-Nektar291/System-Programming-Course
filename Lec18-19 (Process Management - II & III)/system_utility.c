#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(char *cmd);

int main(int argc, char const *argv[])
{
    printf("%s\n", "Running ls command using mysystem");
    mysystem("ls -l /home/jilani/Desktop");
    printf("%s\n", "Done....By");
    exit(0);
}

int mysystem(char *cmd)
{
    int cpid = fork();

    if (cpid == -1)
    {
        fprintf(stderr, "%s\n", "Fork Failed");
        return -1;
    }

    if (cpid == 0)
    {
        execlp("/bin/bash", "myls", "-c", cmd, NULL);
        perror("Exevlp Failed");
        return -2;
    }

    else
    {
        waitpid(cpid, NULL, 0);
        return 0;
    }
}