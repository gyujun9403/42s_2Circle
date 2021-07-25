#include "push_swap.h"

void	push_other_to_this(t_container *other, t_container *this)
{
	t_list	*temp;

	if (other->leng < 1)
		return ;
	temp = other->end;
	other->end->previous->next = other->start;
	other->start->previous = other->end->previous;
	other->end = other->end->previous;
	if (this->leng != 0)
	{
		this->end->next = temp;
		temp->previous = this->end;
		this->start->previous = temp;
		temp->next = this->start;
		this->end = temp;
	}
	else
	{
		this->end = temp;
		this->start = temp;
		this->end->next = this->start;
		this->end->previous = this->end;
	}
	--other->leng;
	++this->leng;
}

void	pa(t_container *container_a, t_container *container_b, int *count)
{
	push_other_to_this(container_b, container_a);
	if (container_a->end->data > container_a->max)
		container_a->max = container_a->end->data;
	if (container_a->end->data < container_a->min)
		container_a->min = container_a->end->data;
	if (container_a->end->data == container_b->min
		|| container_a->end->data == container_b->max)
		set_min_max(container_b);
	++(*count);
	write(1, "pa\n", 3);
	// show_list(container_a);
	// show_list(container_b);
}

void	pb(t_container *container_a, t_container *container_b, int *count)
{
	push_other_to_this(container_a, container_b);
	if (container_b->end->data > container_b->max)
		container_b->max = container_b->end->data;
	if (container_b->end->data < container_b->min)
		container_b->min = container_b->end->data;
	if (container_b->end->data == container_a->min
		|| container_b->end->data == container_a->max)
		set_min_max(container_a);
	++(*count);
	write(1, "pb\n", 3);
	// show_list(container_a);
	// show_list(container_b);
}
