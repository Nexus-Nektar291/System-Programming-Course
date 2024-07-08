#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Invalid number of arguments!\n");
        exit(1);
    }
    struct stat sb;

    if (lstat(argv[1], &sb) == -1)
    {
        perror("lstat failur");
        exit(EXIT_FAILURE);
    }

    printf("File type : ");

    switch (sb.st_mode & S_IFMT)
    {
    case S_IFBLK:
        printf("block device\n");
        break;
    case S_IFCHR:
        printf("character device\n");
        break;
    case S_IFDIR:
        printf("directory\n");
        break;
    case S_IFIFO:
        printf("FIFO/pipe\n");
        break;
    case S_IFLNK:
        printf("symlink\n");
        break;
    case S_IFREG:
        printf("regular file\n");
        break;
    case S_IFSOCK:
        printf("socket\n");
        break;
    default:
        printf("unknown?\n");
        break;
    }
    return 0;
}
