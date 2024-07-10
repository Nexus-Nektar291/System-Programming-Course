#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char const *argv[])
{
    char buff[1024];
    mknod("myfifo", S_IFIFO | 0666, 0);
    printf("%s\n", "Waiting for reading...");
    int writefd = open("myfifo", O_WRONLY);
    printf("%s\n", "Got a reader -- type some text to be sent...");
    while (fgets(buff, sizeof(buff), stdin))
    {
        write(writefd, buff, sizeof(buff));
    }
    printf("%s\n", "Text sent to the FIFO.");

    return 0;
}
