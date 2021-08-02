/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:51:36 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 21:51:38 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	find_bigger(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	element_swap(int *a, int *b)
{
	int	temp;

	temp = (*a);
	*a = *b;
	(*b) = temp;
}
