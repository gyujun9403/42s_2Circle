/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:26:29 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/02 17:26:17 by gyeon            ###   ########.fr       */
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

typedef struct s_tiles
{
	void	*img;
	int		width;
	int		height;
	t_list	*coor;
}	t_tiles;

typedef struct s_collectibles
{
	void	*img;
	int		width;
	int		height;
	t_list	*coor;
}	t_collectibles;

typedef struct s_map
{
	t_tiles	*lst_tile;
	t_collectibles	*lst_collectible;

};

#endif