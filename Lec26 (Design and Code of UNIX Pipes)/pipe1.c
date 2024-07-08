#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 25
int main(int argc, char const *argv[])
{
    char msg[] = "Hello, world! (Using Pipes)\n";
    char buf[SIZE];

    int fd[2];
    int ret = pipe(fd);
    if (ret == -1)
    {
        perror("pipe");
        return -1;
    }

    int w = write(fd[1], msg, sizeof(msg));
    int r = read(fd[0], buf, w);

    write(1, msg, r);
    while (1)
        ;
    return 0;
}
