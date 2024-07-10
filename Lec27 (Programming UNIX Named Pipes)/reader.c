#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char buff[1024];
    int num;
    mknod("myfifo", S_IFIFO | 0666, 0);
    printf("Waiting for writers...\n");
    int readfd = open("myfifo", O_RDONLY);
    printf("Got a writer...\n");

    do
    {
        num = read(readfd, buff, sizeof(buff));
        buff[num] = '\0';
        printf("Reader read %d bytes : %s\n", num, buff);
    } while (num > 0);

    return 0;
}
