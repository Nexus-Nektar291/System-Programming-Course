#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <grp.h>

extern int errno;

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("You must enter one command line argument i.e GID \n ");
        exit(1);
    }

    int gid = atoi(argv[1]);
    errno = 0;
    struct group *grp = getgrgid(gid);
    if (grp == NULL)
    {
        if (errno == 0)
        {
            printf("No record found ! ");
        }
        perror("getgrgid error");
    }
    printf("Group Name : %s\n", grp->gr_name);
    return 0;
}
