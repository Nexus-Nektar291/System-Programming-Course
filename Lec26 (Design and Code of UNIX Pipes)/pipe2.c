#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
int main(int argc, char const *argv[])
{
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1)
    {
        perror("pipe");
        return -1;
    }

    pid_t pid = fork();

    if (pid != 0)
    {
        char msg[] = "Welcome to Communication using pipes.\n";

        close(fd[0]);
        write(fd[1], msg, sizeof(msg));
        waitpid(pid, NULL, 0);
        exit(0);
    }

    else
    {
        close(fd[1]);
        char buffer[1024];
        fprintf(stderr, "Message sent from parent is : ");
        int r = read(fd[0], buffer, sizeof(buffer));
        write(1, buffer, r);
        exit(0);
    }

    return 0;
}
