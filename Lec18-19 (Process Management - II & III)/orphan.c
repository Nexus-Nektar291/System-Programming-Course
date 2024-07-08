#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int cpid = fork();
	if(cpid == 0)
	{
		printf("This is child process. PID = %ld   PPID = %ld \n",(long)getpid(),(long)getppid());
		while(1);
	}

	else
	{
		printf("This is parent process. PID = %ld   PPID = %ld \n",(long)getpid(),(long)getppid());
		exit(0);
	}
	return 0;
}
