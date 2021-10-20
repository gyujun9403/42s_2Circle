/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/20 18:00:16 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int ac, char **av)
{
	t_map	map_info;

	if (ac != 2)
		exit(1);
	map_info.cnt_action = 0;
	map_info.parsed_map = parse_map(av[1]);
	map_info.data_mlx.mlx = mlx_init();
	if (map_info.data_mlx.mlx == NULL)
		mlx_error();
	map_info.dir_root = ft_strdup(av[0]);
	map_info.dir_root = ft_strtrim(map_info.dir_root, TARGET);
	init_map(&map_info);
	match_map2list(&map_info);
	map_info.data_mlx.win = mlx_new_window(map_info.data_mlx.mlx,
			map_info.data_mlx.win_width, map_info.data_mlx.win_height,
			"gyeon's so_long");
	if (map_info.data_mlx.win == NULL)
		mlx_error();
	prt_all_objs(&map_info);
	mlx_key_hook(map_info.data_mlx.win, key_press, &map_info);
	mlx_hook(map_info.data_mlx.win, 17, 0, close_game, &map_info);
	mlx_loop(map_info.data_mlx.mlx);
	return (0);
}
