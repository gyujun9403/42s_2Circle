/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:31:03 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/05 21:47:35 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmds_len(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i] != NULL)
		i++;
	return (i);
}

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] != '\0')
		return (i);
	else
		return (-1);
}

char	**dump_new_string(char **cmd_set, int st, int end)
{
	char	*space;
	char	**result;
	int		i;

	i = 0;
	result = ft_calloc(cmds_len(cmd_set) + end - st + 2, sizeof(char **));
	while (i < st)
	{
		result[i] = cmd_set[i];
		++i;
	}
	result[st] = ft_strjoin(result[st], cmd_set[i++]);
	while (i <= end)
	{
		space = (char *)malloc(2);
		space[0] = ' ';
		space[1] = '\0';
		result[st] = ft_strjoin(result[st], space);
		result[st] = ft_strjoin(result[st], cmd_set[i]);
		++i;
	}
	while (cmd_set[i++] != NULL)
		result[st + i - end - 1] = cmd_set[i - 1];
	return (result);
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
		if (cmd_set[i][0] == '\'')
		{
			st = i;
			while (cmd_set[i++] != NULL && end == 0)
				if (find_char(cmd_set[i - 1], '\'') + 1
					== ft_strlen(cmd_set[i - 1]))
					end = i - 1;
			if (end == 0)
				end = i - 1;
			return (dump_new_string(cmd_set, st, end));
		}
		i++;
	}
	return (cmd_set);
}
