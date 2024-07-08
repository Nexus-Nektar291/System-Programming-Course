#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>

extern int errno;

int main()
{
    puts("Directory scan of ~/Desktop\n");
    DIR *dp = opendir("/home/jilani/Desktop");
    chdir("/home/jilani/Desktop");
    errno = 0;

    struct dirent *entry;
    while (1)
    {
        entry = readdir(dp);

        if (entry == NULL && errno != 0)
        {
            perror("readdir");
            return errno;
        }

        if (entry == NULL && errno == 0)
        {
            printf("\nEND OF DIRECTORY\n");
            return 0;
        }
        printf("%s  ", entry->d_name);
    }
    closedir(dp);
    return 0;
}
