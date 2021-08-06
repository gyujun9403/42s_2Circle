/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:59:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:14:07 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_container(t_container *a, t_container *b)
{
	a->start = NULL;
	a->end = NULL;
	a->leng = 0;
	b->start = NULL;
	b->end = NULL;
	b->leng = 0;
}

int	main(int ac, char **av)
{
	t_container	a;
	t_container	b;

	set_container(&a, &b);
	if (ac != 1)
	{
		if (set_lists(&a, ac, av) == TRUE)
		{
			if (a_is_sorted(&a, a.leng) == FALSE || a.leng > 1)
				quick_a(&a, &b, a.leng);
		}
		else
			write(2, "Error\n", 6);
		free_list(&a, FREE_ALL);
		free_list(&b, FREE_ALL);
		return (0);
	}
}
