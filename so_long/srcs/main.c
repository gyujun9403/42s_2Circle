/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:33:23 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/09 22:03:58 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(void)
{
	t_map	map_info;

	map_info.cnt_action = 0;
	map_info.parsed_map = parse_map();
	if (map_info.parsed_map == NULL)
		prt_map_error();
	map_info.data_mlx.mlx = mlx_init();
	if (init_map(map_info.data_mlx.mlx, &map_info) == ERROR)
		return (prt_img_error());
	if (match_map2list(&map_info) == FALSE)
		return (prt_map_error());
	map_info.data_mlx.win = mlx_new_window(map_info.data_mlx.mlx,
			map_info.data_mlx.win_width, map_info.data_mlx.win_height,
			"gyeon's so_long");
	prt_all_objs(&map_info);
	mlx_key_hook(map_info.data_mlx.win, key_press, &map_info);
	mlx_hook(map_info.data_mlx.win, 17, 0, close_game, &map_info);
	mlx_loop(map_info.data_mlx.mlx);
	return (0);
}
