#include "push_swap.h"

void	sort_two_a(t_container *container_a, int *count)
{
	if (container_a->end->previous->data > container_a->end->data)
		sa(container_a, count);
}

void	sort_two_b(t_container *container_b, int *count)
{
	if (container_b->end->previous->data < container_b->end->data)
		sb(container_b, count);
}

void	sort_just_three_a(t_container *container_a, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(container_a);
	if (num_of_cases == CASE1)
		;
	else if (num_of_cases == CASE2)
	{
		rra(container_a, count);
		sa(container_a, count);
	}
	else if (num_of_cases == CASE3)
		sa(container_a, count);
	else if (num_of_cases == CASE4)
		ra(container_a, count);
	else if (num_of_cases == CASE5)
		rra(container_a, count);
	else if (num_of_cases == CASE6)
	{
		rra(container_a, count);
		sa(container_a, count);
	}
}

void	sort_just_three_b(t_container *container_b, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(container_b);
	if (num_of_cases == CASE1)
	{
		rb(container_b, count);
		sb(container_b, count);
	}
	else if (num_of_cases == CASE2)
		rb(container_b, count);
	else if (num_of_cases == CASE3)
		rrb(container_b, count);
	else if (num_of_cases == CASE4)
	{
		rrb(container_b, count);
		sb(container_b, count);
	}
	else if (num_of_cases == CASE5)
		sb(container_b, count);
	else if (num_of_cases == CASE6)
		;
}
