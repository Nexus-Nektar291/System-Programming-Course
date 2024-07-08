#include <stdio.h>
#include <unistd.h>
int main()
{
    char *arglist[4];
    arglist[0] = "ls";
    arglist[1] = "-l";
    arglist[2] = "/home";
    arglist[3] = NULL;
    execvp(arglist[0], arglist);
    return 0;
}
