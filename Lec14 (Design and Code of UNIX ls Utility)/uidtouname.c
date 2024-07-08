#include <stdio.h>
#include <errno.h>
#include <pwd.h>
#include <stdlib.h>

extern int errno;

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("You must enter one command line argument, i.e UID \n");
        exit(1);
    }
    int uid = atoi(argv[1]);
    errno = 0;
    struct passwd *pwd = getpwuid(uid);
    if (pwd == NULL)
    {
        if (errno == 0)
        {
            printf("Record not found in passwd file !");
        }
        perror("getpwuid error");
    }

    printf("Username : %s\n", pwd->pw_name);
    return 0;
}
