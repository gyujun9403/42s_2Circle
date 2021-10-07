/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coor_and_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:28:47 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/07 16:25:56 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	set_coor(t_list **coor, int x, int y)
{
	//처음인경우, 리스트를 추가하고
	//아닌경우 맨 뒤에 추가해서
	//content 마지막 리스트 원소에
	t_list	*temp;
	int		*coor_data;

	coor_data = (int *)malloc(2 * sizeof(int));
	if (coor_data == NULL)
		return (FALSE);
	coor_data[0] = x;
	coor_data[1] = y;
	temp = ft_lstnew(coor_data);
	if (temp == NULL)
	{
		free(coor_data);
		return (FALSE);
	}
	if (*coor == NULL)
		*coor = temp;
	else
		ft_lstlast(*coor)->next = temp;
	return (TRUE);
}

int	tour_parsed_map(t_map *map_info)
{
	int	x;
	int	y;
	t_list	*temp;

	x = 0;
	y = 0;
	temp = map_info->parsed_map;
	while (temp != NULL)
	{
		x = 0;
		while (((char *)(temp->content))[x] != '\0')
		{
			if (((char *)(temp->content))[x] == WALL)
			{
				if (set_coor(&map_info->wall_info.coor, x * OBJ_W, y * OBJ_H) == FALSE)
					return (FALSE);
			}
			else if (((char *)(temp->content))[x] == EXIT)
			{
				if (set_coor(&map_info->exit_info.coor, x * OBJ_W, y * OBJ_H) == FALSE)
					return (FALSE);
			}
			else if (((char *)(temp->content))[x] == COLLECTIBLE)
			{
				if (set_coor(&map_info->coll_info.coor, x * OBJ_W, y * OBJ_H) == FALSE)
					return (FALSE);
			}
			else if (((char *)(temp->content))[x] == PLAYER)
			{
				if (set_coor(&map_info->player_info.coor, x * PLAYER_W, y * PLAYER_H) == FALSE)
					return (FALSE);
			}
			if (set_coor(&map_info->empty_info.coor, x * OBJ_W, y * OBJ_H) == FALSE)
				return (FALSE);
			++x;
		}
		++y;
		temp = temp->next;
	}
	map_info->data_mlx.win_width = x * OBJ_W;
	map_info->data_mlx.win_height = y * OBJ_H;
	return (TRUE);
}
