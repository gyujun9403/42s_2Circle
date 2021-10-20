/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:39:24 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/20 17:53:14 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_n_set_obj(void *mlx, t_obj *obj, char *dir_root, char *dir_file)
{
	char	*temp;

	temp = ft_strjoin(dir_root, dir_file);
	if (temp == NULL)
		return (ERROR);
	obj->img
		= mlx_xpm_file_to_image(mlx, temp, &(obj->width), &(obj->height));
	free(temp);
	if (obj->img == NULL)
		return (ERROR);
	obj->coor = NULL;
	return (TRUE);
}

int	init_map(t_map *map_info)
{
	void	*mlx;

	mlx = map_info->data_mlx.mlx;
	if (check_n_set_obj(mlx, &(map_info->empty_info),
			map_info->dir_root, FILE_EMPTY) == ERROR)
		mlx_error();
	if (check_n_set_obj(mlx, &(map_info->wall_info),
			map_info->dir_root, FILE_WALL) == ERROR)
		mlx_error();
	if (check_n_set_obj(mlx, &(map_info->exit_info),
			map_info->dir_root, FILE_EXIT) == ERROR)
		mlx_error();
	if (check_n_set_obj(mlx, &(map_info->coll_info),
			map_info->dir_root, FILE_COLL) == ERROR)
		mlx_error();
	if (check_n_set_obj(mlx, &(map_info->player_info),
			map_info->dir_root, FILE_PLAYER) == ERROR)
		mlx_error();
	return (TRUE);
}
