#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *thread_function(void *arg)
{
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    printf("Locking an already locked error checking mutex returns with error.\n");
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
    pthread_mutex_init(&mutex, &attr);

    pthread_t t1;
    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_join(t1, NULL);

    printf("Bye Bye from main.\n");
    return 0;
}
