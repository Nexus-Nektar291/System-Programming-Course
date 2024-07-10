#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

long balance = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *inc(void *arg)
{
    for (long i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        balance++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *dec(void *arg)
{
    for (long i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        balance--;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, inc, NULL);
    pthread_create(&t2, NULL, dec, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Value of balance is : %ld\n", balance);
    pthread_mutex_destroy(&mutex);
    return 0;
}
