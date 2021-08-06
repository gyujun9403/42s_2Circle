/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:59:38 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:14:50 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_b(t_container *a, t_container *b)
{
	if (b->end->previous->data > b->end->data)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_two_a(t_container *a)
{
	if (a->end->previous->data < a->end->data)
		sa(a);
}

/*
** sort_just_three_b must sort like [BOTTOM]1 2 3[TOP]
** error_case : list size is 
** case1 : 1 2 3
** case2 : 2 1 3
** case3 : 1 3 2
** case4 : 2 3 1
** case5 : 3 1 2
** case6 : 3 2 1
*/
void	sort_just_three_b(t_container *a, t_container *b)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(b);
	if (num_of_cases == CASE1)
		;
	else if (num_of_cases == CASE2)
	{
		rrb(b);
		sb(b);
	}
	else if (num_of_cases == CASE3)
		sb(b);
	else if (num_of_cases == CASE4)
		rb(b);
	else if (num_of_cases == CASE5)
		rrb(b);
	else if (num_of_cases == CASE6)
	{
		rb(b);
		sb(b);
	}
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

/*
** sort_just_three_a must sort like [BOTTOM]3 2 1[TOP]
** error_case : list size is 
** case1 : 1 2 3
** case2 : 2 1 3
** case3 : 1 3 2
** case4 : 2 3 1
** case5 : 3 1 2
** case6 : 3 2 1
*/
void	sort_just_three_a(t_container *a)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(a);
	if (num_of_cases == CASE1)
	{
		ra(a);
		sa(a);
	}
	else if (num_of_cases == CASE2)
		ra(a);
	else if (num_of_cases == CASE3)
		rra(a);
	else if (num_of_cases == CASE4)
	{
		rra(a);
		sa(a);
	}
	else if (num_of_cases == CASE5)
		sa(a);
	else if (num_of_cases == CASE6)
		;
}
