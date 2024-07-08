#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t cpid = fork();
	if(cpid == 0)
	{
		printf("%s\n","Hello i am child.");
		sleep(1);
		printf("%s%ld.\n","I am child again and my PID is ",(long)getpid());
		sleep(1);
		printf("%s\n","I am child again and i am terminating.");
		sleep(1);
		exit(7);
	}

	else
	{
		int status;
		int rv = wait(&status);
		printf("%s\n","Hello i am parent.");
		int low_8 = status & 0xff;
		int high_8 = status >> 8;
		if (low_8 == 0)
		{
			printf("%s%d%s%d.\n","Return value of wait is ",rv," and status is ",high_8);
		}
		exit(54);
	}
	return 0;
}
