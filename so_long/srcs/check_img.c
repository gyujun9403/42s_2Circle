/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:39:24 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/04 18:18:28 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_obj(void *mlx, t_obj *obj, char* file_dir)
{
	obj->img = mlx_png_file_to_image(mlx, file_dir, &obj->width, &obj->height);
	if (obj->img == NULL)
		return(ERROR);
	printf("%s\nwidth : %d, height : %d\n",file_dir, obj->width, obj->height);
	if (obj->width != OBJ_W || obj->height != OBJ_H)
		return(ERROR);
	obj->coor = NULL;
	return (TRUE);
}

int	check_player(void *mlx, t_player *player, char* file_dir)
{
	printf("ddd");
	player->img
		= mlx_png_file_to_image(mlx, file_dir, &player->width, &player->height);
	if (player->img == NULL)
		return(ERROR);
	if (player->width != PLAYER_W || player->height != PLAYER_H)
		return(ERROR);
	return (TRUE);
}

int init_map(void *mlx, t_map *map)
{
	void *img;
	int w;
	int h;
	//map->coll_info->img = mlx_png_file_to_image(mlx, FILE_EMPTY, &map->coll_info->width, &map->coll_info->height);
	// if (check_obj(mlx, map->empty_info, FILE_EMPTY) == ERROR)
	// 	return (ERROR); //ERROR
	// if (check_obj(mlx, map->wall_info, FILE_WALL) == ERROR)
	// 	return (ERROR);
	// if (check_obj(mlx, map->exit_info, FILE_EXIT) == ERROR)
	// 	return (ERROR); //ERROR
	if (check_obj(mlx, map->coll_info, FILE_COLL) == ERROR)
		return (ERROR);
	// if (check_player(mlx, map->player_info, FILE_PLAYER) == ERROR)
	// 	return (ERROR); //error
	return (TRUE);
}