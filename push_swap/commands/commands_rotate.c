/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:49:37 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:03:10 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 'rotate' command increases all list's alemnts(move to -> direction).
** last list element(=top of stack) goes to first(=buttom of stack).
*/
void	ra(t_container *container_a)
{
	container_a->start = container_a->end;
	container_a->end = container_a->end->previous;
	write(1, "ra\n", 3);
}

void	rb(t_container *container_b)
{
	container_b->start = container_b->end;
	container_b->end = container_b->end->previous;
	write(1, "rb\n", 3);
}

void	rr(t_container *container_a, t_container *container_b)
{
	container_a->start = container_a->end;
	container_a->end = container_a->end->previous;
	container_b->start = container_b->end;
	container_b->end = container_b->end->previous;
	write(1, "rr\n", 3);
}
