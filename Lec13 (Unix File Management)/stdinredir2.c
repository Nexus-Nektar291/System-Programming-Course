#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buff[100];
	puts("Enter your input here : ");
	fgets(buff,100,stdin);
	printf("You Entered : %s\n",buff);

	int fd = open("/etc/passwd",O_RDONLY);
	close(0);

	int newfd = dup(fd);
	//close(fd);

	fgets(buff,100,stdin);
	printf("Data read from file : %s\n",buff);
	return 0;
}
