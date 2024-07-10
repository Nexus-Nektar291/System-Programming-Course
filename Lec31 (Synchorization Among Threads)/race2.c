#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

int count = 0;
void *word_count(void *arg)
{
    char *filename = (char *)arg;
    int fd = open(filename, O_RDONLY);
    char ch;
    while ((read(fd, &ch, 1)) != 0)
    {
        count++;
    }
    close(fd);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, word_count, (void *)argv[1]);
    pthread_create(&t2, NULL, word_count, (void *)argv[2]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Number of characters in both files : %d\n", count);
    return 0;
}
