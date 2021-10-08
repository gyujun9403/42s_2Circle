/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:04:50 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/08 10:44:11 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE	1
# define FALSE	0
# define ERROR	-1
# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define OBJ_W		64
# define OBJ_H		64
# define PLAYER_W	64
# define PLAYER_H	64
# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define FILE_MAP "./map/map.bar"
# define FILE_EMPTY "./imgs/empty.xpm"
# define FILE_WALL "./imgs/wall.xpm"
# define FILE_COLL "./imgs/coll.xpm"
# define FILE_EXIT "./imgs/exit.xpm"
# define FILE_PLAYER "./imgs/player.xpm"

#endif