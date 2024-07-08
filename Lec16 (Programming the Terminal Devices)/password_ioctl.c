#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>

int main()
{
    char passwd[50];
    printf("Enter your password here : ");

    // GET TERMINAL ATTRIBUTES
    struct termios info;
    ioctl(0, TCGETS, &info);

    // SAVE A COPY OF ORIGINAL ATTRIBUTES
    struct termios save = info;

    // MAKE THE ECHO BIT OFF AND SET THE ATTRIBUTES
    info.c_lflag = info.c_lflag & ~ECHO;
    ioctl(0, TCSETS, &info);

    // GET PASSWORD FROM THE USER
    fgets(passwd, 50, stdin);
    char *q;
    q = strchr(passwd, '\n');
    *q = '\0';

    // SET THE ATTRIBUTES BACK TO ORIGINAL
    ioctl(0, TCSETS, &save);

    // COMPARE THE PASSWORD
    if (!strcmp(passwd, "jilani"))
        printf("\nPassword is correct\n");
    else
        printf("\nPassword is incorrect\n");

    return 0;
}
