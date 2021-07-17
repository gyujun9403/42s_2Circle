#include "push_swap.h"
#include <stdio.h>

void show_list(t_container *container)
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
	t_container	stack_a;
	t_container	stack_b;

	stack_a.leng = 0;
	stack_b.leng = 0;
	i = 0;
	if (ac == 1)
		;
	else
	{
		if (set_lists(&stack_a, ac, av) == TRUE)
		{
			/*show_list(&stack_a);
			pa(&stack_a, &stack_b, &count);
			show_list(&stack_a);
			show_list(&stack_b);
			pb(&stack_a, &stack_b, &count);
			show_list(&stack_a);
			show_list(&stack_b);
			pa(&stack_a, &stack_b, &count);
			show_list(&stack_a);
			show_list(&stack_b);*/
			sa(&stack_a, &count);
			show_list(&stack_a);
			ss(&stack_a, &stack_b, &count);
			show_list(&stack_a);
			ra(&stack_a, &count);
			show_list(&stack_a);
			rr(&stack_a, &stack_b, &count);
			show_list(&stack_a);
			rra(&stack_a, &count);
			show_list(&stack_a);
			rrr(&stack_a, &stack_b, &count);
			show_list(&stack_a);
		}
		else
			write(1, "FAIL!\n", 6);
	}
}
