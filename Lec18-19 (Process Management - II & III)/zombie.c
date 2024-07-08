#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int cpid = fork();
	if(cpid == 0)
	{
		printf("Child process PID = %ld\n",(long)getpid());
		exit(0);
	}
	else
	{
		printf("Parent process PID = %ld\n",(long)getpid());
		while(1);
	}
	return 0;
}
