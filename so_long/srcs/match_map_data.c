/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:28:47 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/20 18:00:02 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	set_coor(t_list **coor, int x, int y)
{
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

t_list	**get_obj(t_map *map_info, char c)
{
	if (c == WALL)
		return (&map_info->wall_info.coor);
	else if (c == EXIT)
		return (&map_info->exit_info.coor);
	else if (c == COLLECTIBLE)
		return (&map_info->coll_info.coor);
	else if (c == PLAYER)
		return (&map_info->player_info.coor);
	return (NULL);
}

int	match_map2list(t_map *map_info)
{
	int		x;
	int		y;
	t_list	*temp;
	t_list	**obj;

	y = 0;
	temp = map_info->parsed_map;
	while (temp != NULL)
	{
		x = 0;
		while (((char *)(temp->content))[x] != '\0')
		{
			obj = get_obj(map_info, ((char *)(temp->content))[x]);
			if (obj != NULL)
				if (set_coor(obj, x * OBJ_W, y * OBJ_W) == FALSE)
					malloc_error();
			if (!set_coor(&map_info->empty_info.coor, x++*OBJ_W, y * OBJ_H))
				malloc_error();
		}
		++y;
		temp = temp->next;
	}
	map_info->data_mlx.win_width = x * OBJ_W;
	map_info->data_mlx.win_height = y * OBJ_H;
	return (TRUE);
}
