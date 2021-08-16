#include "pipex.h"

#include <stdio.h>

int main()
{
	pid_t pid[2];
	pid_t ret[2];

	pid[0] = fork();
	if (pid[0] == -1)
		return (-1);
	else if (pid[0] == 0)
	{
		usleep(200);
		printf("this is child.1\n");
		usleep(200);
		printf("this is child.1\n");
		usleep(200);
		printf("this is child.1\n");
		usleep(200);
		printf("this is child.1\n");
	}
	else
	{
		printf("%d child has born.\n", pid[0]);
		pid[1] = fork();
		if (pid[1] == -1)
			return (-1);
		else if (pid[1] == 0)
		{
			usleep(200);
			printf("this is child.2\n");
			usleep(200);
			printf("this is child.2\n");
			usleep(200);
			printf("this is child.2\n");
			usleep(200);
			printf("this is child.2\n");
		}
		else
		{
			printf("%d child has born.\n", pid[1]);
			ret[0] = wait(NULL);
			printf("%d child has been retrieved.\n", ret[0]);
			ret[1] = wait(NULL);
			printf("%d child has been retrieved.\n", ret[1]);
		}
	}
	return 0;
}