/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:26:29 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/08 17:13:43 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> //open, 
# include <unistd.h> //close, read, write
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <string.h> //strerror
# include "./defines.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "../get-next-line/get_next_line_bonus.h"
# include "../libft/libft.h"

typedef struct s_obj
{
	void	*img;
	int		width;
	int		height;
	t_list	*coor;
}	t_obj;

typedef struct s_mlxwin
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
}	t_mlxwim;

typedef struct s_map
{
	t_list		*parsed_map;
	t_mlxwim	data_mlx;
	t_obj		empty_info;
	t_obj		wall_info;
	t_obj		coll_info;
	t_obj		player_info;
	t_obj		exit_info;
	int			cnt_action;
}	t_map;

int		prt_map_error(void);
int		prt_img_error(void);
int		check_map(t_list *lst);
int		init_map(void *mlx, t_map *map);
t_list	*parse_map(void);
int		match_map2list(t_map *map_info);
void	prt_all_objs(t_map *map_info);
int		close_game(t_map *map_info);
int		key_press(int pressed_key, t_map *map_info);

#endif