/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 22:30:59 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 23:31:23 by gyeon            ###   ########.fr       */
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

void	sort_four_a(t_container *a, t_container	*b, int *count)
{
	int	i;
	int	mid;

	i = 0;
	mid = find_mid(a);
	while (i++ < 4)
	{
		if (a->end->data >= mid)
			ra(a, count);
		else
			pb(a, b, count);
	}
	if (a->leng != 2)
	{
		rra(a, count);
		rra(a, count);
	}
	sort_two_a(a, count);
	sort_two_b(a, b, count);
}

void	sort_four_b(t_container *a, t_container	*b, int *count)
{
	int	i;
	int	mid;

	i = 0;
	mid = find_mid(b);
	while (i++ < 4)
	{
		if (b->end->data >= mid)
			pa(a, b, count);
		else
			rb(b, count);
	}
	if (b->leng != 2)
	{
		rrb(b, count);
		rrb(b, count);
	}
	sort_two_a(a, count);
	sort_two_b(a, b, count);
}
