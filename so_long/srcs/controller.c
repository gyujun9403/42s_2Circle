/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:58:24 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/21 18:03:48 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_moveable(t_map *map_info, int add_x, int add_y)
{
	t_list	*temp;
	int		player_x;
	int		player_y;

	temp = map_info->wall_info.coor;
	player_x = ((int *)map_info->player_info.coor->content)[0] + add_x;
	player_y = ((int *)map_info->player_info.coor->content)[1] + add_y;
	while (temp != NULL)
	{
		if (((int *)temp->content)[0] == player_x
			&& ((int *)temp->content)[1] == player_y)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	check_collectable(t_map *map_info)
{
	t_list	*temp;
	t_list	*pre_temp;
	int		player_x;
	int		player_y;

	pre_temp = NULL;
	temp = map_info->coll_info.coor;
	player_x = ((int *)map_info->player_info.coor->content)[0];
	player_y = ((int *)map_info->player_info.coor->content)[1];
	while (temp != NULL)
	{
		if (((int *)temp->content)[0] == player_x
			&& ((int *)temp->content)[1] == player_y)
		{
			if (pre_temp != NULL)
				pre_temp->next = temp->next;
			else
				map_info->coll_info.coor = temp->next;
			ft_lstdelone(temp, free);
			return (TRUE);
		}
		pre_temp = temp;
		temp = temp->next;
	}
	return (FALSE);
}

int	check_exitable(t_map *map_info)
{
	t_list	*temp;
	int		player_x;
	int		player_y;

	temp = map_info->exit_info.coor;
	player_x = ((int *)map_info->player_info.coor->content)[0];
	player_y = ((int *)map_info->player_info.coor->content)[1];
	while (temp != NULL)
	{
		if (((int *)temp->content)[0] == player_x
			&& ((int *)temp->content)[1] == player_y
			&& map_info->coll_info.coor == NULL)
			return (TRUE);
		temp = temp->next;
	}
	return (FALSE);
}

int	set_movement_controll(int pressed_key, int *move_x, int *move_y)
{
	*move_x = 0;
	*move_y = 0;
	if (pressed_key == KEY_A)
		*move_x = -OBJ_W;
	else if (pressed_key == KEY_W)
		*move_y = OBJ_H;
	else if (pressed_key == KEY_S)
		*move_y = -OBJ_H;
	else if (pressed_key == KEY_D)
		*move_x = OBJ_W;
	else
		return (FALSE);
	return (TRUE);
}

int	key_press(int pressed_key, t_map *map_info)
{
	int	move_x;
	int	move_y;

	if (pressed_key == KEY_ESC)
		exit(0);
	if (set_movement_controll(pressed_key, &move_x, &move_y) == FALSE)
		return (FALSE);
	if (check_moveable(map_info, move_x, move_y) == FALSE)
		return (FALSE);
	++map_info->cnt_action;
	((int *)map_info->player_info.coor->content)[0] += move_x;
	((int *)map_info->player_info.coor->content)[1] += move_y;
	prt_all_objs(map_info);
	check_collectable(map_info);
	if (check_exitable(map_info) == TRUE)
		close_game(map_info);
	return (TRUE);
}
