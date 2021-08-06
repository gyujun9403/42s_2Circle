/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:50:26 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:04:18 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_container *container)
{
	t_list	*temp;

	if (container->leng < 2)
		return ;
	else if (container->leng == 2)
	{
		temp = container->start;
		container->start = container->end;
		container->end = temp;
		return ;
	}
	temp = container->end->previous;
	container->end->previous->previous->next = container->end;
	container->end->previous = container->end->previous->previous;
	container->end->next = temp;
	temp->previous = container->end;
	temp->next = container->start;
	container->start->previous = temp;
	container->end = temp;
}

void	sa(t_container *container)
{
	swap(container);
	write(1, "sa\n", 3);
}

void	sb(t_container *container)
{
	swap(container);
	write(1, "sb\n", 3);
}

void	ss(t_container *container_a, t_container *container_b)
{
	swap(container_a);
	swap(container_b);
	write(1, "ss\n", 3);
}
