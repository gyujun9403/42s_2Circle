/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:36:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/08 16:49:17 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// t_path_list	*make_list(int num)
// {
// 	int i;
// 	t_path_list	*list_start;
// 	t_path_list	*list_ptr;

// 	i = 0;
// 	list_start = malloc(sizeof(t_path_list));
// 	if (list_start == NULL)
// 		return (NULL);
// 	list_ptr = list_start;
// 	while (i++ + 1 < num)
// 	{
// 		list_ptr->next = malloc(sizeof(t_path_list));
// 		if (list_ptr->next == NULL)
// 		{
// 			free_lists(list_start);
// 			return (NULL);
// 		}
// 		list_ptr = list_ptr->next;	
// 	}
// 	list_ptr->next = NULL;
// 	return (list_start);
// }

char	**make_cmd_set(char* cmd)
{
	char** cmd_set;

	cmd_set = ft_split(cmd, ' ');
	if (cmd_set == NULL)
		return (NULL);
	cmd_set = check_inner_string(cmd_set);
	return (cmd_set);
}

// t_path_list	*index_of_list(t_path_list *list_start, int index)
// {
// 	int i;

// 	i = 0;
// 	while (i++ < index)
// 		list_start = list_start->next;
// 	return (list_start);
// }
