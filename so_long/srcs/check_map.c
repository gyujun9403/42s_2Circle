/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:57:17 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/20 17:53:28 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_usable_word(char word)
{
	return (word == EMPTY || word == WALL || word == COLLECTIBLE
		|| word == EXIT || word == PLAYER);
}

int	check_line_just_one(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		if (line[i++] != '1')
			return (ERROR);
	return (i);
}

int	check_line(char *line)
{
	static short	flg_player = 0;
	int				i;

	i = 0;
	if (line[0] != '1')
		return (ERROR);
	while (line[i] != '\0')
	{
		if (check_usable_word(line[i]) == FALSE)
			return (ERROR);
		else if (line[i] == PLAYER)
		{
			if (flg_player == 0)
				++flg_player;
			else
				return (ERROR);
		}
		if ((line[i + 1] == '\0' && line[i] != '1')
			|| i >= MAX_WIDTH)
			return (ERROR);
		++i;
	}
	return (i);
}

int	check_map(t_list *lst)
{
	int	width;

	if (lst == NULL || lst->content == NULL)
		map_error();
	if (ft_lstsize(lst) >= MAX_HEIGHT)
		map_error();
	width = check_line_just_one((char *)lst->content);
	if (width == ERROR || width < 3)
		map_error();
	if (lst->next != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			if (lst->content != NULL)
			{
				if (check_line((char *)lst->content) != width)
					map_error();
			}
		}
		if (check_line_just_one((char *)lst->content) != width)
			map_error();
		return (TRUE);
	}
	return (map_error());
}
