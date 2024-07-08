#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();

    // CHILD WILL READ FROM FD2[0] AND WRITE INTO FD1[1]
    if (pid == 0)
    {
        close(fd1[0]);
        close(fd2[1]);

        char msgfromchild[] = "This is the message send from child process to parent.";
        char childbuff[1024];

        // CHILD RECEIVES THE MESSAGE FROM THE PARENT
        int r = read(fd2[0], childbuff, sizeof(childbuff));
        write(1, childbuff, r);
        puts("");

        // CHILD SEND A RESPONSE TO PARENT
        int w = write(fd1[1], msgfromchild, sizeof(msgfromchild));

        exit(0);
    }

    // PARENT WILL READ FROM FD1[0] AND WRITE INTO FD2[1]
    else
    {
        close(fd1[1]);
        close(fd2[0]);

        char msgfromparent[] = "This is the message send from parent process to child.";
        char parentbuff[1024];

        // PARENT SEND A RESPONSE TO CHILD
        int w = write(fd2[1], msgfromparent, sizeof(msgfromparent));

        // PARENT RECEIVES THE MESSAGE FROM THE CHILD
        int r = read(fd1[0], parentbuff, sizeof(parentbuff));
        write(1, parentbuff, r);
        puts("");

        // wait(NULL);
        exit(0);
    }
    return 0;
}
