#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 512
#define MAXARGS 10
#define ARGLEN 30

char *read_cmd(FILE *fp);
char **tokenize(char *cmdline);

int main()
{
    printf("Enter a command of your choice : ");
    char *cmdline = read_cmd(stdin);
    char **arglist = tokenize(cmdline);
    execvp(arglist[0], arglist);
    perror("Exec Failed");
    return 0;
}

char *read_cmd(FILE *fp)
{
    int c;
    int pos = 0;
    char *cmdline = (char *)malloc(sizeof(char) * MAX_LEN);
    while ((c = getc(fp)) != EOF)
    {
        if (c == '\n')
        {
            break;
        }
        cmdline[pos] = c;
        pos++;
    }
    cmdline[pos] = '\0';
    return cmdline;
}

char **tokenize(char *cmdline)
{
    char **arglist = (char **)malloc(sizeof(char *) * (MAXARGS + 1));
    for (int i = 0; i < MAXARGS + 1; i++)
    {
        arglist[i] = (char *)malloc(sizeof(char) * ARGLEN);
        bzero(arglist[i], ARGLEN);
    }

    char *cp = cmdline;
    char *start;
    int len;
    int argnum = 0;
    while (*cp != '\0')
    {
        while (*cp == ' ' || *cp == '\t')
        {
            cp++;
        }
        start = cp;
        len = 1;
        while (*++cp != '\0' && !(*cp == ' ' || *cp == '\t'))
        {
            len++;
        }
        strncpy(arglist[argnum], start, len);
        arglist[argnum][len] = '\0';
        argnum++;
    }
    arglist[argnum] = NULL;
    return arglist;
}