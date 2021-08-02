/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:59:43 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 21:59:43 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_set_rsrr_b(t_container *b, int *count)
{
	rb(b, count);
	sb(b, count);
	rrb(b, count);
}

void	command_set_rsrr_a(t_container *a, int *count)
{
	ra(a, count);
	sa(a, count);
	rra(a, count);
}

void	command_set_ppp_a(t_container *a, t_container *b, int *count)
{
	pa(a, b, count);
	pa(a, b, count);
	pa(a, b, count);
}

void	sort_top_three_b(t_container *a, t_container *b, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(b);
	if (num_of_cases == CASE2)
		command_set_rsrr_b(b, count);
	else if (num_of_cases == CASE3)
		sb(b, count);
	else if (num_of_cases == CASE4)
	{
		sb(b, count);
		command_set_rsrr_b(b, count);
	}
	else if (num_of_cases == CASE5)
	{
		command_set_rsrr_b(b, count);
		sb(b, count);
	}
	else if (num_of_cases == CASE6)
	{
		sb(b, count);
		command_set_rsrr_b(b, count);
		sb(b, count);
	}
	command_set_ppp_a(a, b, count);
}

void	sort_top_three_a(t_container *a, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(a);
	if (num_of_cases == CASE1)
	{
		sa(a, count);
		command_set_rsrr_a(a, count);
		sa(a, count);
	}
	else if (num_of_cases == CASE2)
	{
		sa(a, count);
		command_set_rsrr_a(a, count);
	}
	else if (num_of_cases == CASE3)
	{
		command_set_rsrr_a(a, count);
		sa(a, count);
	}
	else if (num_of_cases == CASE4)
		command_set_rsrr_a(a, count);
	else if (num_of_cases == CASE5)
		sa(a, count);
	else if (num_of_cases == CASE6)
		;
}
