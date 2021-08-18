#include "pipex.h"

#include <stdio.h>

int	check_access(char *file_name)
{
	if (access(file_name, F_OK) == -1)
	{
		strerror
		return (-1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		;
	else if (ac > 3)
	{

	}
	return 0;
}