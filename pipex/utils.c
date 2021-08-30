/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:36:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/30 15:14:31 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*make_list(int num)
{
	int i;
	t_list	*list_start;
	t_list	*list_ptr;

	i = 0;
	list_start = malloc(sizeof(t_list));
	if (list_start == NULL)
		return (NULL);
	list_ptr = list_start;
	while (i++ < num)
	{
		list_ptr = list_ptr->next;
		list_ptr = malloc(sizeof(t_list));
		if (list_ptr == NULL)
			return (NULL);
	}
	return (list_start);
}

char	**make_cmd_set(char* cmd)
{
	char** cmd_set;

	cmd_set = ft_split(cmd, ' ');
	if (cmd_set == NULL)
		return (NULL);
	//if (access(cmd_set[0], X_OK | R_OK) == -1)
	//	return (NULL);
	return (cmd_set);
}

t_list	*index_of_list(t_list *list_start, int index)
{
	int i;

	i = 0;
	while (i++ < index)
		list_start = list_start->next;
	return (list_start);
}

void	free_lists(t_list *list_start)
{
	int i;

	i = 0;
	while (list_start == NULL)
	{
		while (list_start->content[i++] != NULL)
			free(list_start->content[i - 1]);
		free(list_start->content);
		list_start = list_start->next;
	}
}