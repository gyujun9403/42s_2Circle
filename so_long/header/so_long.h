/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:26:29 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/02 15:32:03 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> //open, 
# include <unistd.h> //close, read, write
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <string.h> //strerror
# include "../minilibx_opengl_20191021/mlx.h"
# include "../get-next-line/get_next_line_bonus.h"
# include "../libft/libft.h"

# define MAP "../map/map.bar"
# define TILE_ASSET "../img/50*50tile.png"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// typedef struct s_data_map
// {
// 	char				*line;
// 	struct s_data_map	*next;
// }	t_data_map;

typedef	struct s_list_coor
{
	int					x;
	int					y;
	struct s_list_coor	*next;
}	t_list_coor;


typedef struct s_tiles
{
	void		*img;
	int			width;
	int			height;
	t_list_coor	*coor;
}	t_tiles;



#endif