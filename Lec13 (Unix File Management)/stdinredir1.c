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
	close(0);

	int fd = open("/etc/passwd",O_RDONLY);
	fgets(buff,100,stdin);
	printf("Data read from file : %s\n",buff);
	return 0;
}
