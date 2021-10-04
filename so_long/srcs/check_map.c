/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:57:17 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/04 15:20:32 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
1. 0빈공간, 1벽, C수집품, E탈출구, P플레이어로만 구성된다.
	-> 해당 요소가 없는게 있다면 에러
	-> 맵이 그냥 EMPTY인 경우 에러
2. 맵은 벽에 의이 닫혀있어야한다.
	-> 첫번째줄 마지막줄은 전부 1, 각 줄의 첫과 끝은 1이여야한다.
	-> 마지막 줄 뒤에 개행은 봐줄수 있지만, 그 이외 다른 데이터가 오면 에러
3. 맵은 사각형이다.
	-> 첫번째 줄의 길이를 저장하고 이후 길이가 바뀌면 바로 에러.
4. 잘못되면 Error\n출력하고 lst free, NULL반환
	좋은 맵이면 파싱한 위치정보를 반환.
*/

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
	int	i;

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
		if (line[i + 1] == '\0' && line[i] != '1')
			return (ERROR);
		++i;
	}
	return (i);
}

int	check_map(t_list *lst)
{
	int	width;

	if (lst == NULL || lst->content == NULL)
		return (ERROR);
	width = check_line_just_one((char *)lst->content);
	if (width == ERROR)
		return (ERROR);
	if (lst->next != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			if (lst->content != NULL)
				if (check_line((char *)lst->content) != width)
				{
					return (ERROR);
				}
		}
		if (check_line_just_one((char *)lst->content) != width)
			return (ERROR);
		return (TRUE);
	}
	return (ERROR);
}
