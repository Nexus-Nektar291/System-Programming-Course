#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int maxargs;
    printf("How many arguments you want to enter(including the cmd): ");
    scanf("%d", &maxargs);
    char **arglist = (char **)malloc(sizeof(char *) * (maxargs + 1));
    for (int i = 0; i < maxargs + 1; i++)
        arglist[i] = (char *)malloc(sizeof(char) * 10);

    int i = 0;
    while (i < maxargs)
    {
        printf("arglist[%d]: ", i);
        scanf("%s", arglist[i]);
        i++;
    }
    arglist[i] = NULL;
    execvp(arglist[0], arglist);
    perror("Exec failed");
    return 0;
}
