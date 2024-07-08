#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "%s\n", "Invalid number of arguments provide a ttyname");
        exit(1);
    }

    int fd = open(argv[1], 1);

    if (fd == -1)
    {
        perror("Open Failed");
        exit(1);
    }

    char buff[512];
    while (fgets(buff, 512, stdin) != NULL)
        if (write(fd, buff, strlen(buff)) == -1)
            break;
    close(fd);
    return 0;
}
