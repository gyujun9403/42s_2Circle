/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:33:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/25 17:24:18 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	int i;
	char **env_path;
	char *temp;

	i = 0;
	while (env[i] != NULL)
	{
		if(ft_strnstr(env[i++], "PATH=", 6) != NULL)
		{
			env_path = ft_split(env[i - 1], ':');
			temp = env_path[0];
			env_path[0] = ft_strdup(&temp[5]);
			free(temp);
			break;
		}
	}
	return env_path;
}

// env_path를 받고, 없는 명령어가 있다면 전부 free하고 NULL반환,
// 있으면 char**형태의 입력명령들의 경로를 저장한다. 그리고 env_path를 free한다. 
char	*check_cmd(char **path, char *cmd)
{
	char	*temp;
	int i;
	int len_path;
	int len_cmd;

	i = 0;	
	while (path[i++] != NULL)
	{
		len_path = ft_strlen(path[i - 1]);
		len_cmd = ft_strlen(cmd);
		temp = ft_calloc(len_path + len_cmd + 2, sizeof(char));
		ft_strlcat(temp, path[i - 1], len_path + 1);
		ft_strlcat(temp, "/", len_path + 2);
		ft_strlcat(temp, cmd, len_path + len_cmd + 2);
		if (access(temp, F_OK | X_OK) == 0)
		{
			return (temp);
			break ;
		}
		free(temp);
	}
	return NULL;
}

char	**make_cmds(int ac, char **av, char **env)
{
	int	i;
	char	**env_path;
	char	**cmds;

	i = 1;
	cmds = ft_calloc(ac - 1, sizeof(char*));
	env_path = find_path(env);
	while (i++ + 1 < ac)
	{
		cmds[i - 2] = check_cmd(env_path, av[i]);
		if (cmds[i - 2] == NULL)
		{
			free_strs(env_path);
			free_strs(cmds);
			prt_command_not_found(av[i]);
			return NULL;
		}
	}
	free_strs(env_path);
	return cmds;
}