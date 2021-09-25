/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:42:52 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/24 20:30:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	free_arrs(char **arrs)
{
	int	i;

	i = 0;
	while (arrs[i] != NULL)
	{
		free(arrs[i]);
		++i;
	}
	free(arrs);
	return (FALSE);
}

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
