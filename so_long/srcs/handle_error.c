/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:31:16 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/19 22:59:20 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_error(void)
{
	ft_putstr_fd("ERROR\nCheck your map.\n", 2);
	exit (1);
}

int	mlx_error(void)
{
	ft_putstr_fd("ERROR\nMlx error occured.\n", 2);
	exit (1);
}

int	malloc_error(void)
{
	ft_putstr_fd("ERROR\nMalloc error occured.\n", 2);
	exit (1);
}

int	img_error(void)
{
	ft_putstr_fd("ERROR\nCheck your img.\n", 2);
	exit (1);
}
