#include "pipex.h"

#include <stdio.h>

int	main(int ac, char **av, char **env)
{

	if (ac < 2)
		return -1;
	char *file = av[1];
	char *temp_str;
	int fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		temp_str = ft_calloc(ft_strlen(file) + 7, sizeof(char));
		ft_strlcat(temp_str, "bash: ", 7);
		ft_strlcat(temp_str, file, 7 + ft_strlen(file));
		perror(temp_str);
		free(temp_str);
	}
	else
		close(fd);
	int i = 0;
	char **env_path;
	char *temp;
	while (env[i] != NULL) {
		if(ft_strnstr(env[i++], "PATH=", 6) != NULL)
		{
			env_path = ft_split(env[i - 1], ':');
			temp = env_path[0];
			env_path[0] = ft_strdup(&temp[5]);
			free(temp);
			break;
		}
		else
			;
	}
	i = 0;
	while (env_path[i++] != NULL)
	{
		printf("%s\n", env_path[i - 1]);
		free(env_path[i - 1]);
	}
	free(env_path);
}