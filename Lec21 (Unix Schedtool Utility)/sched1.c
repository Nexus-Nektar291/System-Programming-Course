#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int main()
{
	int nv = nice(+0);
	printf("Original nice value = %d\n",nv);
	nv = nice(+7);
	printf("By incrementing nice value by 7 it becomes = %d\n",nv);

	errno = 0;

	// ONLY ROOT CAN GIVE A NEGATIVE VALUE
	nv = nice(-2);
	if(nv == -1 && errno != 0)
	{
		perror("Nice Failed");
		exit(1);
	}

	printf("Decrementing the nice value by 2 it becomes = %d\n",nv);
	return 0;
}
