/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/07 16:28:11 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h" 

void prt_two_int(void *ptr)
{
	printf("[0]\t: %d\n", ((int *)ptr)[0]);
	printf("[1]\t: %d\n", ((int *)ptr)[1]);
}

int	set_imgs_using_coor(t_map *map_info, int kind)
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
	else //if (kind == PLAYER)
		sel = map_info->player_info;
	temp = sel.coor;
	if (temp == NULL)
		return (FALSE);
	while (temp != NULL)
	{
		mlx_put_image_to_window(map_info->data_mlx.mlx, 
			map_info->data_mlx.win, 
			sel.img,((int *)(temp->content))[0], ((int *)(temp->content))[1]);
		temp = temp->next;
	}
	return (TRUE);
}

int main()
{
	int		i;
	t_map	map_info;

	map_info.parsed_map = parse_map();
	if (map_info.parsed_map == NULL)
		prt_map_error();
	map_info.data_mlx.mlx = mlx_init();
	if (init_map(map_info.data_mlx.mlx, &map_info) == ERROR)
	 	return (prt_img_error());
	if (tour_parsed_map(&map_info) == FALSE)
		prt_map_error();
	map_info.data_mlx.win = mlx_new_window(map_info.data_mlx.mlx, map_info.data_mlx.win_width, map_info.data_mlx.win_height, "Hello MLX!");
	set_imgs_using_coor(&map_info, EMPTY);
	set_imgs_using_coor(&map_info, WALL);
	set_imgs_using_coor(&map_info, EXIT);
	set_imgs_using_coor(&map_info, COLLECTIBLE);
	set_imgs_using_coor(&map_info, PLAYER);
	mlx_loop(map_info.data_mlx.mlx);
	return (0);
}