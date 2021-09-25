/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:25:04 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/25 14:59:45 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

char	*add_space(char *src)
{
	char	*result;
	char	*space;

	space = (char *)malloc(2);
	if (space == NULL)
		exit (1);
	space[0] = ' ';
	space[1] = '\0';
	result = ft_strjoin(src, space);
	if (result == NULL)
		exit (1);
	return (result);
}

char	**dump_new_string(char **cmd_set, int st, int end)
{
	char	**result;
	int		i;

	i = 0;
	result = ft_calloc(cmds_len(cmd_set) + end - st + 2, sizeof(char **));
	if (result == NULL)
		exit (1);
	while (i <= st)
	{
		result[i] = cmd_set[i];
		++i;
	}
	while (i <= end)
	{
		result[st] = add_space(result[st]);
		result[st] = ft_strjoin(result[st], cmd_set[i++]);
		if (result[st] == NULL)
			exit (1);
	}
	result[st] = ft_strtrim(result[st], "\'");
	while (cmd_set[i++] != NULL)
		result[st + i - end - 1] = cmd_set[i - 1];
	return (result);
}
