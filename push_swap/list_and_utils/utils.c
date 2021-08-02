/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:49:17 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 22:21:23 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_atoi(char *str, int *num_container)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*(str++) - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			return (NULL);
	}
	if (!(*str == ' ' || *str == '\0'))
		return (NULL);
	*num_container = num * sign;
	return (str);
}

/*
** aesc
*/
int	a_is_sorted(t_container *container_a, int check)
{
	int		i;
	int		num_check;
	t_list	*temp;

	i = 1;
	temp = container_a->end;
	if (check != -1)
		num_check = check;
	else
		num_check = container_a->leng;
	while (i++ < num_check)
	{
		if (temp->previous->data < temp->data)
			return (FALSE);
		temp = temp->previous;
	}
	return (TRUE);
}

/*
** desc
*/
int	b_is_sorted(t_container *container_b, int check)
{
	int		i;
	int		num_check;
	t_list	*temp;

	i = 1;
	temp = container_b->end;
	if (check != -1)
		num_check = check;
	else
		num_check = container_b->leng;
	while (i++ < num_check)
	{
		if (temp->previous->data > temp->data)
			return (FALSE);
		temp = temp->previous;
	}
	return (TRUE);
}

/*
** error_case : list size is 
** case1 : ... 1 2 3
** case2 : ... 2 1 3
** case3 : ... 1 3 2
** case4 : ... 2 3 1
** case5 : ... 3 1 2
** case6 : ... 3 2 1
*/
int	compare_top_three(t_container *container)
{
	int	first;
	int	second;
	int	third;

	if (container->leng < 3)
		return (ERROR_CASE);
	first = container->end->data;
	second = container->end->previous->data;
	third = container->end->previous->previous->data;
	if (first > second && second > third)
		return (CASE1);
	else if (first > third && third > second)
		return (CASE2);
	else if (second > first && first > third)
		return (CASE3);
	else if (second > third && third > first)
		return (CASE4);
	else if (third > first && first > second)
		return (CASE5);
	else
		return (CASE6);
}
