#include "push_swap.h"
#include <stdio.h>

void	set_container (t_container *a, t_container *b)
{
	a->max = -2147483648;
	a->min = 2147483647;
	a->start = NULL;
	a->end = NULL;
	a->leng = 0;
	b->max = -2147483648;
	b->min = 2147483647;
	b->start = NULL;
	b->end = NULL;
	b->leng = 0;
}

void	show_list(t_container *container)
{
	char		data;
	int			i;
	t_list	*ptr;

	i = 0;
	ptr = container->start;
	while (i++ < container->leng)
	{
		//data = ptr->data + '0';
		printf("%d\t", ptr->data);
		//write(1, &data, 1);
		//write(1, "\t", 1);
		ptr = ptr->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	int			i;
	int			count;
	t_container	container_a;
	t_container	container_b;

	set_container(&container_a, &container_b);
	i = 0;
	if (ac == 1)
		;
	else
	{
		if (set_lists(&container_a, ac, av) == TRUE)
		{
			//show_list(&container_a);
			if (a_is_sorted(&container_a, container_a.leng) == FALSE || container_a.leng > 1)
			{
				if (container_a.leng == 2)
					sort_two_a(&container_a, &count);
				else if (container_a.leng == 3)
					sort_just_three_a(&container_a, &count);
				else
					quick_sort(&container_a, &container_b, &count);
			}
			//show_list(&container_a);
			//printf("count : %d", count);
		}
		else
			write(1, "Error\n", 6);
	}
}
