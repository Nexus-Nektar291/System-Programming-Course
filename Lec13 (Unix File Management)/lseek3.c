#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int holes = atoi(argv[1]);
    int fd = open("fileswithholes", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "JILANI", 6);

    for (int i = 0; i < holes; i++)
    {
        lseek(fd, 10, SEEK_CUR);
        write(fd, "JILANI", 6);
    }
    close(fd);
    return 0;
}
