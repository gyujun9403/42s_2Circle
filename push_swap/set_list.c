#include "push_swap.h"

int	check_overlap_list(t_container *container, int num)
{
	int		i;
	t_list	*ptr;

	if (container->leng == 1)
	{
		if (container->start->data == num)
			return (FALSE);
	}
	else
	{
		i = 0;
		ptr = container->start;
		while (i++ < container->leng)
		{
			if (ptr->data == num)
				return (FALSE);
			ptr = ptr->next;
		}
	}
	return (TRUE);
}

int	add_list(t_container *container, int num)
{
	if (container->leng == 0)
	{
		container->start = (t_list *)malloc(sizeof(t_list));
		if (container->start == NULL)
			return (free_list(container, FREE_ALL));
		container->end = container->start;
		container->start->data = num;
		container->start->next = container->start;
		container->start->previous = container->start;
	}
	else
	{
		container->end->next = (t_list *)malloc(sizeof(t_list));
		if (container->end->next == NULL)
			return (free_list(container, FREE_ALL));
		if (check_overlap_list(container, num) == FALSE)
			return (free_list(container, FREE_ALL));
		container->end->next->data = num;
		container->end->next->previous = container->end;
		container->end->next->next = container->start;
		container->end = container->end->next;
	}
	container->leng++;
	return (TRUE);
}

// str에 아무것도 없는경우, 있긴 한데 이상한게 끼어있거나 int범위 넘는 경우... false.
// str에 아무것도 없는 경우는 ' '다 날렸는데, 문자열 끝인경우
// str에 이상한게 있는 경우나 int범위 넣는 경우는 ps_atoi에서 null을 반환한다.

int	ac_to_list(t_container *container, char *str)
{
	char	*st_ptr;
	char	*temp_ptr;
	int		num;

	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (free_list(container, FREE_ALL));
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break ;
		str = ps_atoi(str, &num);
		if (str == NULL)
			return (free_list(container, FREE_ALL));
		if (add_list(container, num) == FALSE)
			return (free_list(container, FREE_ALL));
	}
	return (TRUE);
}

int	set_lists(t_container *container, int ac, char **av)
{
	int	i;

	if (container != NULL)
	{
		i = 1;
		while (i < ac)
			if (ac_to_list(container, *(av + i++)) == FALSE)
				return (free_list(container, FREE_ALL));
	}
	return (TRUE);
}

int	free_list(t_container *container, short flg)
{
	t_list	*ptr;
	short	once;

	once = FALSE;
	while (container->leng
		&& (flg == FREE_ALL || (flg == FREE_ONE && once == FALSE)))
	{
		ptr = container->end;
		container->end = container->end->previous;
		container->end->next = container->start;
		container->start->previous = container->end;
		once = TRUE;
		free(ptr);
		if (--(container->leng) == 0)
		{
			container->start = NULL;
			container->end = NULL;
		}
	}
	return (FALSE);
}
