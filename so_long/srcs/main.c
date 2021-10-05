/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/05 17:21:15 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h" 

int main()
{
	int		i;
	t_map	map_info;

	map_info.parsed_map = parse_map();
	if (map_info.parsed_map == NULL)
		prt_map_error();
	t_list *temp;
	temp = map_info.parsed_map;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	map_info.data_mlx.mlx = mlx_init();
	map_info.data_mlx.win = mlx_new_window(map_info.data_mlx.mlx, 1920, 1080, "Hello MLX!");
	if (init_map(map_info.data_mlx.mlx, &map_info) == ERROR)
	 	return (prt_img_error());
	printf("%p\n", map_info.data_mlx.mlx);
	printf("%p\n", map_info.data_mlx.win);
	mlx_put_image_to_window(map_info.data_mlx.mlx, map_info.data_mlx.win, map_info.empty_info.img, 0, 0);
	mlx_put_image_to_window(map_info.data_mlx.mlx, map_info.data_mlx.win, map_info.wall_info.img, 0, 50);
	mlx_put_image_to_window(map_info.data_mlx.mlx, map_info.data_mlx.win, map_info.coll_info.img, 50, 0);
	mlx_put_image_to_window(map_info.data_mlx.mlx, map_info.data_mlx.win, map_info.exit_info.img, 100, 0);
	mlx_put_image_to_window(map_info.data_mlx.mlx, map_info.data_mlx.win, map_info.player_info.img, 50, 50);
	mlx_loop(map_info.data_mlx.mlx);
	return (0);
}