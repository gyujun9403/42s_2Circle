/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:33:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/08 17:04:10 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	int		i;
	char	**env_path;
	char	*temp;

	i = 0;
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

int	make_cmd(char **path, char **cmd_set)
{
	char	*temp;
	int		i;
	int		len_path;
	int		len_cmd;

	i = 0;
	while (path[i++] != NULL)
	{
		len_path = ft_strlen(path[i - 1]);
		len_cmd = ft_strlen(cmd_set[0]);
		temp = ft_calloc(len_path + len_cmd + 2, sizeof(char));
		ft_strlcat(temp, path[i - 1], len_path + 1);
		ft_strlcat(temp, "/", len_path + 2);
		ft_strlcat(temp, cmd_set[0], len_path + len_cmd + 2);
		if (access(temp, F_OK | X_OK) == 0)
		{
			free(cmd_set[0]);
			cmd_set[0] = temp;
			return (TRUE);
		}
		free(temp);
	}
	return (FALSE);
}

//int	make_cmds(int ac, char **av, char **env, t_container *cont)
char	**make_cmds(char *cmd_chunk)
{
	//int			i;
	//t_path_list	*temp;
	//char		**path;
	char **result;

	//i = 0;
	//cont->cnt_cmds = ac - 3;
	//cont->list = make_list(ac - 3);
	//if (cont->list == NULL)
	//	return (FALSE);
	//path = find_path(env);
	// while (i + 3 < ac)
	// {
		//temp = index_of_list(cont->list, i);
		//temp->cmds = make_cmd_set(av[i + 2]);
		//if (temp->cmds == NULL)
		//	return (free_lists(cont->list));
		// if (make_cmd(path, temp->cmds) == FALSE)
		// {
		// 	prt_command_not_found(temp->cmds[0]);
		// 	return (free_lists(cont->list));
		// }
	// 	i++;
	// }
	//free(path);
	//result = make_cmd_set(cmd_chunk);
	return (NULL);
}

int	check_files(int ac, char **av)
{
	int result;
	
	result = TRUE;
	if (access(av[1], F_OK) == -1)
	{
		prt_no_such_file(av[1]);
		result = FALSE;
	}
	else if (access(av[1], R_OK) == -1)
	{
		prt_file_permission_deny(av[1]);
		result = FALSE;
	}
	if (access(av[ac - 1], W_OK) == -1)
	{
		prt_file_permission_deny(av[ac - 1]);
		result = FALSE;
	}
	return (result);
}
