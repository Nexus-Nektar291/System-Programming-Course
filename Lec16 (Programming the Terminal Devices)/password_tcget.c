#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

int main()
{
    char passwd[50];
    printf("Enter your password here : ");

    // GET TERMINAL ATTRIBUTES
    struct termios info;
    tcgetattr(0, &info);

    // SAVE A COPY OF ORIGINAL ATTRIBUTES
    struct termios save = info;

    // MAKE THE ECHO BIT OFF AND SET THE ATTRIBUTES
    info.c_lflag = info.c_lflag & ~ECHO;
    tcsetattr(0, TCSANOW, &info);

    // GET PASSWORD FROM THE USER
    fgets(passwd, 50, stdin);
    char *q;
    q = strchr(passwd, '\n');
    *q = '\0';

    // SET THE ATTRIBUTES BACK TO ORIGINAL
    tcsetattr(0, TCSANOW, &save);

    // COMPARE THE PASSWORD
    if (!strcmp(passwd, "jilani"))
        printf("\nPassword is correct\n");
    else
        printf("\nPassword is incorrect\n");

    return 0;
}
