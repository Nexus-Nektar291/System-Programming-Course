#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char **ptr;
void *thread_function(void *arg)
{
    int myid = (*(int *)arg);
    static int svar = 0;
    printf("[%d] : %s (svar = %d)\n", myid, ptr[myid], ++svar);
    pthread_exit(NULL);
}
int main(int argc, char const *argv[])
{
    pthread_t tid[2];
    char *msg[2] = {"Hello from Jilani", "Hello from UET"};
    ptr = msg;
    for (int i = 0; i < 2; i++)
    {
        pthread_create(&tid[i], NULL, thread_function, (void *)&i);
        pthread_join(tid[i], NULL);
    }
    return 0;
}
