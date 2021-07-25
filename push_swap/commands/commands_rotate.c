#include "push_swap.h"

/*
** 'rotate' command increases all list's alemnts(move to -> direction).
** last list element(=top of stack) goes to first(=buttom of stack).
*/
void	ra(t_container *container_a, int *count)
{
	container_a->start = container_a->end;
	container_a->end = container_a->end->previous;
	++(*count);
	write(1, "ra\n", 3);
	// show_list(container_a);
}

void	rb(t_container *container_b, int *count)
{
	container_b->start = container_b->end;
	container_b->end = container_b->end->previous;
	++(*count);
	write(1, "rb\n", 3);
	// show_list(container_b);
}

void	rr(t_container *container_a, t_container *container_b, int *count)
{
	container_a->start = container_a->end;
	container_a->end = container_a->end->previous;
	container_b->start = container_b->end;
	container_b->end = container_b->end->previous;
	++(*count);
	write(1, "rr\n", 3);
}
