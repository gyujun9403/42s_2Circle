/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:31:03 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/25 14:59:50 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

char	**make_cmd_set(char *cmd)
{
	char	**cmd_set;

	cmd_set = ft_split(cmd, ' ');
	if (cmd_set == NULL)
		return (NULL);
	cmd_set = check_inner_string(cmd_set);
	return (cmd_set);
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

char	**check_inner_string(char **cmd_set)
{
	int	i;
	int	st;
	int	end;

	i = 0;
	end = 0;
	while (cmd_set[i] != NULL)
	{
		if (cmd_set[i++][0] == '\'')
		{
			st = --i;
			if (find_char(&cmd_set[st][1], '\'') + 2
				== (int)ft_strlen(cmd_set[st]))
				end = st;
			else
				while (cmd_set[i++] != NULL && end == 0)
					if (find_char(cmd_set[i - 1], '\'') + 1
						== (int)ft_strlen(cmd_set[i - 1]))
						end = i - 1;
			if (end == 0)
				end = i - 1;
			return (dump_new_string(cmd_set, st, end));
		}
	}
	return (cmd_set);
}

char	**check_and_set_cmds(t_pinfo *pinfo, char *cmd_chunk)
{
	char	**cmd_set;

	cmd_set = make_cmd_set(cmd_chunk);
	if (cmd_set == NULL)
		exit(1);
	if (find_char(cmd_set[0], '/') != -1)
	{
		if (access(cmd_set[0], F_OK | X_OK) == -1)
		{
			prt_command_not_found(cmd_set[0]);
			exit(127);
		}
		return (cmd_set);
	}
	if (make_cmd(pinfo->path, cmd_set) == FALSE)
	{
		prt_command_not_found(cmd_set[0]);
		exit(127);
	}
	return (cmd_set);
}
