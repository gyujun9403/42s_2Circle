/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:50:21 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 21:50:23 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 'reverse rotate' commands decrease all list's alemnts(move to <- direction).
** first list element(=bottom of stack) goes to last(=top of stack).
*/
void	rra(t_container *container_a, int *count)
{
	container_a->end = container_a->start;
	container_a->start = container_a->start->next;
	++(*count);
	write(1, "rra\n", 4);
}

void	rrb(t_container *container_b, int *count)
{
	container_b->end = container_b->start;
	container_b->start = container_b->start->next;
	++(*count);
	write(1, "rrb\n", 4);
}

void	rrr(t_container *container_a, t_container *container_b, int *count)
{
	container_a->end = container_a->start;
	container_a->start = container_a->start->next;
	container_b->end = container_b->start;
	container_b->start = container_b->start->next;
	++(*count);
	write(1, "rrr\n", 4);
}
