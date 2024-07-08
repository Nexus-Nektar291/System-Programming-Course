#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>

int main()
{
	char passwd[100];
	printf("Enter your password here : ");
	system("stty -echo");
	fgets(passwd,100,stdin);

	// Remove '\n' character at the end of input
	char *q;
	q = strchr(passwd,'\n');
	*q = '\0';

	system("stty echo");
	if(!strcmp(passwd,"jilani"))
		printf("\nPassword is correct\n");
	else
		printf("\nPassword is incorrect\n");
	return 0;
}
