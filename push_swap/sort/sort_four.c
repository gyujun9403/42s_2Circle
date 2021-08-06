/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 22:30:59 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:14:49 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid(t_container *container)
{
	int		i;
	int		j;
	int		temp_arr[4];
	t_list	*temp;

	i = 0;
	temp = container->end;
	while (i < 4)
	{
		temp_arr[i++] = temp->data;
		temp = temp->previous;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j + i + 1 < 4)
		{
			if (temp_arr[j] > temp_arr[j + 1])
				element_swap(&temp_arr[j], &temp_arr[j + 1]);
			++j;
		}
		++i;
	}
	return (temp_arr[2]);
}

void	sort_four_a(t_container *a, t_container	*b)
{
	int	i;
	int	mid;

	i = 0;
	mid = find_mid(a);
	while (i++ < 4)
	{
		if (a->end->data >= mid)
			ra(a);
		else
			pb(a, b);
	}
	if (a->leng != 2)
	{
		rra(a);
		rra(a);
	}
	sort_two_a(a);
	sort_two_b(a, b);
}

void	sort_four_b(t_container *a, t_container	*b)
{
	int	i;
	int	mid;

	i = 0;
	mid = find_mid(b);
	while (i++ < 4)
	{
		if (b->end->data >= mid)
			pa(a, b);
		else
			rb(b);
	}
	if (b->leng != 2)
	{
		rrb(b);
		rrb(b);
	}
	sort_two_a(a);
	sort_two_b(a, b);
}
