/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:39:24 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/05 17:20:11 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_obj(void *mlx, t_obj *obj, char* file_dir)
{
	obj->img = mlx_xpm_file_to_image(mlx, file_dir, &(obj->width), &(obj->height));
	if (obj->img == NULL)
		return(ERROR);
	printf("%p : %d, %d\n", obj->img, obj->width, obj->height);
	obj->coor = NULL;
	return (TRUE);
}

int	check_player(void *mlx, t_player *player, char* file_dir)
{
	printf("ddd");
	player->img
		= mlx_xpm_file_to_image(mlx, file_dir, &player->width, &player->height);
	if (player->img == NULL)
		return(ERROR);
	printf("%s : %d, %d\n", file_dir, player->width, player->height);
	printf("%s", file_dir);
	return (TRUE);
}

int init_map(void *mlx, t_map *map)
{
	void *img;
	int w;
	int h;
	if (check_obj(mlx, &(map->empty_info), FILE_EMPTY) == ERROR)
		return (ERROR);
	if (check_obj(mlx, &(map->wall_info), FILE_WALL) == ERROR)
		return (ERROR);
	if (check_obj(mlx, &(map->exit_info), FILE_EXIT) == ERROR)
		return (ERROR);
	if (check_obj(mlx, &(map->coll_info), FILE_COLL) == ERROR)
		return (ERROR);
	if (check_player(mlx, &(map->player_info), FILE_PLAYER) == ERROR)
		return (ERROR);
	return (TRUE);
}