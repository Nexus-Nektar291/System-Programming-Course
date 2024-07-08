#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void show_stat_info(char *fname);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Incorrect number of arguments!\n");
        exit(1);
    }
    show_stat_info(argv[1]);
    return 0;
}

void show_stat_info(char *fname)
{
    struct stat info;
    int rv = lstat(fname, &info);
    if (rv == -1)
    {
        perror("stat failed");
        exit(1);
    }
    printf("Mode : %o\n", info.st_mode);
    printf("Link Count : %ld\n", info.st_nlink);
    printf("User : %d\n", info.st_uid);
    printf("Group : %d\n", info.st_gid);
    printf("Size : %ld\n", info.st_size);
    printf("Mod time : %ld\n", info.st_mtime);
    printf("Name : %s\n", fname);
}
