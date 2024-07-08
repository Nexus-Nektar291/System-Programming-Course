#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void f1();
void f2();
int main()
{
    f1();
    f2();
    printf("\nBye Bye from main\n");
    return 0;
}

void f1()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s", "PUCIT");
        fflush(stdout);
        sleep(1);
    }
}
void f2()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s", "ARIF");
        fflush(stdout);
        sleep(1);
    }
}
