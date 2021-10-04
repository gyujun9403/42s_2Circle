/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:31:16 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/04 17:05:49 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	prt_map_error()
{
	ft_putstr_fd("ERROR\nCheck your map.\n", 2);
	return (ERROR);
}

int	prt_img_error()
{
	ft_putstr_fd("ERROR\nCheck your img.\n", 2);
	return (ERROR);
}