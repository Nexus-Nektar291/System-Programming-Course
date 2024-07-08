#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

extern int errno;

void do_ls(const char *dir);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Enter exactly one argument (directory name).\n");
        exit(1);
    }

    printf("Directory listing of %s : \n", argv[1]);
    do_ls(argv[1]);

    return 0;
}

void do_ls(const char *dir)
{
    struct dirent *entry;
    DIR *dp = opendir(dir);
    if (dp == NULL)
    {
        fprintf(stderr, "Cannot open directory : %s\n", dir);
        return;
    }
    errno = 0;
    while ((entry = readdir(dp)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    if (errno != 0)
    {
        perror("readdir failed");
    }

    closedir(dp);
}