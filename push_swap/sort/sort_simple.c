#include "push_swap.h"

void	sort_two_b(t_container *a, t_container *b, int *count)
{
	if (b->end->previous->data > b->end->data)
		sb(b, count);
	pa(a, b, count);
	pa(a, b, count);
}

void	sort_two_a(t_container *a, int *count)
{
	if (a->end->previous->data < a->end->data)
		sa(a, count);
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
void	sort_just_three_b(t_container *a, t_container *b, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(b);
	if (num_of_cases == CASE1)
		;
	else if (num_of_cases == CASE2)
	{
		rrb(b, count);
		sb(b, count);
	}
	else if (num_of_cases == CASE3)
		sb(b, count);
	else if (num_of_cases == CASE4)
		rb(b, count);
	else if (num_of_cases == CASE5)
		rrb(b, count);
	else if (num_of_cases == CASE6)
	{
		rb(b, count);
		sb(b, count);
	}
	pa(a, b, count);
	pa(a, b, count);
	pa(a, b, count);
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
void	sort_just_three_a(t_container *a, int *count)
{
	int	num_of_cases;

	num_of_cases = compare_top_three(a);
	if (num_of_cases == CASE1)
	{
		ra(a, count);
		sa(a, count);
	}
	else if (num_of_cases == CASE2)
		ra(a, count);
	else if (num_of_cases == CASE3)
		rra(a, count);
	else if (num_of_cases == CASE4)
	{
		rra(a, count);
		sa(a, count);
	}
	else if (num_of_cases == CASE5)
		sa(a, count);
	else if (num_of_cases == CASE6)
		;
}
