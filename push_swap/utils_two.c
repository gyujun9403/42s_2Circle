#include "push_swap.h"

int a_is_rotate_sorted(t_container *container)
{
	int		i;
	t_list *temp;

	i = 0;
	temp = container->start;
	while (temp->data != container->min)
		temp = temp->next;
	while (i++ < container->leng)
	{
		if (temp->data > temp->next->data)
			return (FALSE);
		temp = temp->next;
	}
	
	return (TRUE);
}