/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:57:55 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 21:57:56 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot_a(t_container *container)
{
	int		temp_arr[5];
	t_list	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = container->end;
	while (i < 5)
	{
		temp_arr[i++] = ptr->data;
		ptr = ptr->previous;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j + i + 1 < 5)
		{
			if (temp_arr[j] > temp_arr[j + 1])
				element_swap(&temp_arr[j], &temp_arr[j + 1]);
			++j;
		}
		++i;
	}
	return (temp_arr[3]);
}

void	sort_five_a(t_container *a, t_container	*b, int *count)
{
	int	i;
	int	pivot;

	i = 0;
	pivot = find_pivot_a(a);
	while (i++ < 5)
	{
		if (a->end->data >= pivot)
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
	if (b->leng == 3)
		sort_just_three_b(a, b, count);
	else
		sort_top_three_b(a, b, count);
}

int	find_pivot_b(t_container *container)
{
	int		temp_arr[5];
	t_list	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = container->end;
	while (i < 5)
	{
		temp_arr[i++] = ptr->data;
		ptr = ptr->previous;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j + i + 1 < 5)
		{
			if (temp_arr[j] > temp_arr[j + 1])
				element_swap(&temp_arr[j], &temp_arr[j + 1]);
			++j;
		}
		++i;
	}
	return (temp_arr[1]);
}

void	sort_five_b(t_container *a, t_container *b, int *count)
{
	int	i;
	int	pivot;

	i = 0;
	pivot = find_pivot_b(b);
	while (i++ < 5)
	{
		if (b->end->data <= pivot)
			rb(b, count);
		else
			pa(a, b, count);
	}
	if (b->leng != 2)
	{
		rrb(b, count);
		rrb(b, count);
	}
	if (a->leng == 3)
		sort_just_three_a(a, count);
	else
		sort_top_three_a(a, count);
	sort_two_b(a, b, count);
}
