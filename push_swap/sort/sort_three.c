/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:59:43 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:14:48 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_set_rsrr_b(t_container *b)
{
	rb(b);
	sb(b);
	rrb(b);
}

void	command_set_rsrr_a(t_container *a)
{
	ra(a);
	sa(a);
	rra(a);
}

void	command_set_ppp_a(t_container *a, t_container *b)
{
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_top_three_b(t_container *a, t_container *b)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(b);
	if (num_of_cases == CASE2)
		command_set_rsrr_b(b);
	else if (num_of_cases == CASE3)
		sb(b);
	else if (num_of_cases == CASE4)
	{
		sb(b);
		command_set_rsrr_b(b);
	}
	else if (num_of_cases == CASE5)
	{
		command_set_rsrr_b(b);
		sb(b);
	}
	else if (num_of_cases == CASE6)
	{
		sb(b);
		command_set_rsrr_b(b);
		sb(b);
	}
	command_set_ppp_a(a, b);
}

void	sort_top_three_a(t_container *a)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(a);
	if (num_of_cases == CASE1)
	{
		sa(a);
		command_set_rsrr_a(a);
		sa(a);
	}
	else if (num_of_cases == CASE2)
	{
		sa(a);
		command_set_rsrr_a(a);
	}
	else if (num_of_cases == CASE3)
	{
		command_set_rsrr_a(a);
		sa(a);
	}
	else if (num_of_cases == CASE4)
		command_set_rsrr_a(a);
	else if (num_of_cases == CASE5)
		sa(a);
	else if (num_of_cases == CASE6)
		;
}
