#include "push_swap.h"

void	ra(t_container *container_a, int *count)
{
	container_a->end = container_a->start;
	container_a->start = container_a->start->next;
	++count;
	write(1, "ra\n", 3);
}

void	rb(t_container *container_b, int *count)
{
	container_b->end = container_b->start;
	container_b->start = container_b->start->next;
	++count;
	write(1, "rb\n", 3);
}

void	rr(t_container *container_a, t_container *container_b, int *count)
{
	container_a->end = container_a->start;
	container_a->start = container_a->start->next;
	container_b->end = container_b->start;
	container_b->start = container_b->start->next;
	++count;
	write(1, "rr\n", 3);
}
