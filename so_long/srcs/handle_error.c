/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:31:16 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/08 16:17:08 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	prt_map_error(void)
{
	ft_putstr_fd("ERROR\nCheck your map.\n", 2);
	return (ERROR);
}

int	prt_img_error(void)
{
	ft_putstr_fd("ERROR\nCheck your img.\n", 2);
	return (ERROR);
}
