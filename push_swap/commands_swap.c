#include "push_swap.h"

void	swap(t_container *container)
{
	t_list	*temp;

	if (container->leng < 2)
		return ;
	temp = container->end->previous;
	container->end->previous->previous->next = container->end;
	container->end->previous = container->end->previous->previous;
	container->end->next = temp;
	temp->previous = container->end;
	temp->next = container->start;
	container->start->previous = temp;
	container->end = temp;
}

void	sa(t_container *container, int *count)
{
	swap(container);
	write(1, "sa\n", 3);
	(*count)++;
}

void	sb(t_container *container, int *count)
{
	swap(container);
	write(1, "sb\n", 3);
	(*count)++;
}

void	ss(t_container *container_a, t_container *container_b, int *count)
{
	swap(container_a);
	swap(container_b);
	write(1, "ss\n", 3);
	(*count)++;
}
