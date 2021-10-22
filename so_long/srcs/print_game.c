/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:54:14 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/22 13:05:55 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/* 
** mlx_destroy_window(...); makes leaks.
** So I make OS do free() by using exit().
*/
int	close_game(t_map *map_info)
{
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->empty_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->wall_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->coll_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->exit_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->player_info.img);
	mlx_clear_window(map_info->data_mlx.mlx, map_info->data_mlx.win);
	exit(0);
	return (0);
}

void	prt_obj(t_map *map_info, int kind)
{
	t_obj	sel;
	t_list	*temp;

	if (kind == EMPTY)
		sel = map_info->empty_info;
	else if (kind == WALL)
		sel = map_info->wall_info;
	else if (kind == COLLECTIBLE)
		sel = map_info->coll_info;
	else if (kind == EXIT)
		sel = map_info->exit_info;
	else
		sel = map_info->player_info;
	temp = sel.coor;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		mlx_put_image_to_window(map_info->data_mlx.mlx,
			map_info->data_mlx.win,
			sel.img, ((int *)(temp->content))[0], ((int *)(temp->content))[1]);
		temp = temp->next;
	}
	return ;
}

void	prt_string(t_map *map_info)
{
	char	*cnt_string;
	char	*summed_string;

	cnt_string = ft_itoa(map_info->cnt_action);
	summed_string = ft_strjoin("your action count : ", cnt_string);
	mlx_string_put(map_info->data_mlx.mlx,
		map_info->data_mlx.win,
		25, 25, 0x00FFFFFF, summed_string);
	free(cnt_string);
	free(summed_string);
}

void	prt_all_objs(t_map *map_info)
{
	prt_obj(map_info, EMPTY);
	prt_obj(map_info, WALL);
	prt_obj(map_info, EXIT);
	prt_obj(map_info, COLLECTIBLE);
	prt_obj(map_info, PLAYER);
	prt_string(map_info);
}
