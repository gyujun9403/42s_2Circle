#include "push_swap.h"

void	command_set_rsrr_a(t_container *container_a, int *count)
{
	ra(container_a, count);
	sa(container_a, count);
	rra(container_a, count);
}

void	command_set_rsrr_b(t_container *container_b, int *count)
{
	rb(container_b, count);
	sb(container_b, count);
	rrb(container_b, count);
}

void	sort_top_three_a(t_container *container_a, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(container_a);
	if (num_of_cases == CASE1)
		;
	else if (num_of_cases == CASE2)
		command_set_rsrr_a(container_a, count);
	else if (num_of_cases == CASE3)
		sa(container_a, count);
	else if (num_of_cases == CASE4)
	{
		sa(container_a, count);
		command_set_rsrr_a(container_a, count);
	}
	else if (num_of_cases == CASE5)
	{
		command_set_rsrr_a(container_a, count);
		sa(container_a, count);
	}
	else if (num_of_cases == CASE6)
	{
		sa(container_a, count);
		command_set_rsrr_a(container_a, count);
		sa(container_a, count);
	}
}

void	sort_top_three_b(t_container *container_b, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(container_b);
	if (num_of_cases == CASE1)
	{
		sb(container_b, count);
		command_set_rsrr_b(container_b, count);
		sb(container_b, count);
	}
	else if (num_of_cases == CASE2)
	{
		sb(container_b, count);
		command_set_rsrr_b(container_b, count);
	}
	else if (num_of_cases == CASE3)
	{
		command_set_rsrr_b(container_b, count);
		sb(container_b, count);
	}
	else if (num_of_cases == CASE4)
		command_set_rsrr_b(container_b, count);
	else if (num_of_cases == CASE5)
		sb(container_b, count);
	else if (num_of_cases == CASE6)
		;
}
