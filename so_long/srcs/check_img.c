/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:39:24 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/09 21:37:48 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_n_set_obj(void *mlx, t_obj *obj, char *file_dir)
{
	obj->img
		= mlx_xpm_file_to_image(mlx, file_dir, &(obj->width), &(obj->height));
	if (obj->img == NULL)
		return (ERROR);
	obj->coor = NULL;
	return (TRUE);
}

int	check_n_set_ani(void *mlx, t_obj *obj, char *file_dir)
{
	obj->img
		= mlx_xpm_file_to_image(mlx, file_dir, &(obj->width), &(obj->height));
	if (obj->img == NULL)
		return (ERROR);
	obj->coor = NULL;
	return (TRUE);
}

int	init_map(void *mlx, t_map *map)
{
	if (check_n_set_obj(mlx, &(map->empty_info), FILE_EMPTY) == ERROR)
		return (ERROR);
	if (check_n_set_obj(mlx, &(map->wall_info), FILE_WALL) == ERROR)
		return (ERROR);
	if (check_n_set_obj(mlx, &(map->exit_info), FILE_EXIT) == ERROR)
		return (ERROR);
	if (check_n_set_obj(mlx, &(map->coll_info), FILE_COLL) == ERROR)
		return (ERROR);
	if (check_n_set_obj(mlx, &(map->player_info), FILE_PLAYER) == ERROR)
		return (ERROR);
	return (TRUE);
}
