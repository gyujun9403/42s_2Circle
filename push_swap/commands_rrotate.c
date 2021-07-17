#include "push_swap.h"

void	rra(t_container *container_a, int *count)
{
	container_a->start = container_a->end;
	container_a->end = container_a->end->previous;
	++count;
	write(1, "rra\n", 4);
}

void	rrb(t_container *container_b, int *count)
{
	container_b->start = container_b->end;
	container_b->end = container_b->end->previous;
	++count;
	write(1, "rrb\n", 4);
}

void	rrr(t_container *container_a, t_container *container_b, int *count)
{
	container_a->start = container_a->end;
	container_a->end = container_a->end->previous;
	container_b->start = container_b->end;
	container_b->end = container_b->end->previous;
	++count;
	write(1, "rrr\n", 4);
}
