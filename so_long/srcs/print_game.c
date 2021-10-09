/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:54:14 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/09 22:09:37 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_game(t_map *map_info)
{
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->empty_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->wall_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->coll_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->exit_info.img);
	mlx_destroy_image(map_info->data_mlx.mlx, map_info->player_info.img);
	mlx_clear_window(map_info->data_mlx.mlx, map_info->data_mlx.win);
	mlx_destroy_window(map_info->data_mlx.mlx, map_info->data_mlx.win);
	ft_lstclear(&(map_info->parsed_map), free);
	ft_lstclear(&(map_info->empty_info.coor), free);
	ft_lstclear(&(map_info->wall_info.coor), free);
	ft_lstclear(&(map_info->coll_info.coor), free);
	ft_lstclear(&(map_info->exit_info.coor), free);
	ft_lstclear(&(map_info->player_info.coor), free);
	exit(0);
	return (0);
}

int	prt_obj(t_map *map_info, int kind)
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
		return (FALSE);
	while (temp != NULL)
	{
		mlx_put_image_to_window(map_info->data_mlx.mlx,
			map_info->data_mlx.win,
			sel.img, ((int *)(temp->content))[0], ((int *)(temp->content))[1]);
		temp = temp->next;
	}
	return (TRUE);
}

void	prt_string(t_map *map_info)
{
	char	*cnt_string;
	char	*temp_string;

	cnt_string = ft_itoa(map_info->cnt_action);
	temp_string = ft_strdup("your action count : ");
	temp_string = ft_strjoin(temp_string, cnt_string);
	mlx_string_put(map_info->data_mlx.mlx,
		map_info->data_mlx.win,
		25, 25, 0x00FFFFFF, temp_string);
	free(temp_string);
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
