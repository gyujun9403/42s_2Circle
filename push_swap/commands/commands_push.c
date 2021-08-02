/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:49:29 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 22:11:25 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_other_to_this(t_container *other, t_container *this)
{
	t_list	*temp;

	if (other->leng < 1)
		return ;
	temp = other->end;
	other->end->previous->next = other->start;
	other->start->previous = other->end->previous;
	other->end = other->end->previous;
	if (this->leng != 0)
	{
		this->end->next = temp;
		temp->previous = this->end;
		this->start->previous = temp;
		temp->next = this->start;
		this->end = temp;
	}
	else
	{
		this->end = temp;
		this->start = temp;
		this->end->next = this->start;
		this->end->previous = this->end;
	}
	--other->leng;
	++this->leng;
}

void	pa(t_container *container_a, t_container *container_b, int *count)
{
	push_other_to_this(container_b, container_a);
	++(*count);
	write(1, "pa\n", 3);
}

void	pb(t_container *container_a, t_container *container_b, int *count)
{
	push_other_to_this(container_a, container_b);
	++(*count);
	write(1, "pb\n", 3);
}
