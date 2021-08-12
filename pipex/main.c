#include "pipex.h"

#include <stdio.h>

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		printf("this is child.\n");
	else
		printf("this is parent.\n");
	return 0;
}