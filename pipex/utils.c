/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:42:52 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/05 21:52:02 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_lists(t_path_list *list_start)
{
	int	i;

	while (list_start != NULL)
	{
		i = 0;
		while ((list_start->cmds)[i++] != NULL)
			free((list_start->cmds)[i - 1]);
		free(list_start->cmds);
		list_start = list_start->next;
	}
	return (FALSE);
}

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
