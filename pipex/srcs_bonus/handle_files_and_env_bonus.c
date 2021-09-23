/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files_and_env_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:54:43 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/23 15:23:38 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	openfile_and_dup(char *file, int mode)
{
	int	result;

	result = open(file, mode);
	if (result == -1)
	{
		write(STDOUT_FILENO, "bash: ", 6);
		perror(file);
		exit(1);
	}
	if (mode == O_RDONLY)
	{
		if (dup2(result, STDIN_FILENO) == -1)
			exit(1);
	}
	else
	{
		if (dup2(result, STDOUT_FILENO) == -1)
			exit(1);
	}
	close(result);
}

/* 
** find $PATH from environment variable
*/
char	**find_path(char **env)
{
	int		i;
	char	**env_path;
	char	*temp;

	i = 0;
	env_path = NULL;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i++], "PATH=", 6) != NULL)
		{
			env_path = ft_split(env[i - 1], ':');
			temp = env_path[0];
			env_path[0] = ft_strdup(&temp[5]);
			free(temp);
			break ;
		}
	}
	return (env_path);
}
