/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/19 16:43:42 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int ac, char **av)//, char **envp)
{
	t_map	map_info;

	if (ac != 2)
		exit(1);
	map_info.cnt_action = 0;
	map_info.parsed_map = parse_map(av[1]);
	if (map_info.parsed_map == NULL)
		exit (prt_map_error());
	map_info.data_mlx.mlx = mlx_init();
	if (map_info.data_mlx.mlx == NULL)
		exit (1);
	if (init_map(&map_info) == ERROR)
		exit (prt_img_error());
	if (match_map2list(&map_info) == FALSE)
		exit (prt_map_error());
	map_info.data_mlx.win = mlx_new_window(map_info.data_mlx.mlx,
			map_info.data_mlx.win_width, map_info.data_mlx.win_height,
			"gyeon's so_long");
	if (map_info.data_mlx.win == NULL)
		exit (1);
	prt_all_objs(&map_info);
	mlx_key_hook(map_info.data_mlx.win, key_press, &map_info);
	mlx_hook(map_info.data_mlx.win, 17, 0, close_game, &map_info);
	mlx_loop(map_info.data_mlx.mlx);
	return (0);
}
