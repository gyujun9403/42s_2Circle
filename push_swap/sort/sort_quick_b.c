/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:59:33 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 23:14:40 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_return_b(t_container *a, t_container *b, int *count, int leng)
{
	if (leng <= 5)
	{
		if (leng == 1)
			pa(a, b, count);
		else if (leng == 2)
			sort_two_b(a, b, count);
		else if (leng == 3 && b->leng == 3)
			sort_just_three_b(a, b, count);
		else if (leng == 3)
			sort_top_three_b(a, b, count);
		else if (b_is_sorted(b, leng) == TRUE)
			while (leng-- > 0)
				pa(a, b, count);
		else if (leng == 4)
			sort_four_b(a, b, count);
		else if (leng == 5)
			sort_five_b(a, b, count);
		return (TRUE);
	}
	else
		return (FALSE);
}

void	divide_chunk_b(t_container *a, t_container *b, int *count, int leng)
{
	int	i;
	int	pivot[2];

	i = 0;
	find_two_pivot(b, leng, pivot);
	while (i++ < leng)
	{
		if (b->end->data >= pivot[1])
			pa(a, b, count);
		else
		{
			if (b->end->data >= pivot[0])
			{
				pa(a, b, count);
				ra(a, count);
			}
			else
				rb(b, count);
		}
	}
}

/* pa	-> leng - leng * 2 / 3
** para	-> leng * 2 / 3 - leng / 3
** rb	-> leng / 3
*/
void	quick_b(t_container *a, t_container *b, int *count, int leng)
{
	int	i;

	if (check_return_b(a, b, count, leng) == TRUE)
		return ;
	divide_chunk_b(a, b, count, leng);
	i = 0;
	quick_a(a, b, count, leng - leng * 2 / 3);
	while (i++ < find_smaller(leng / 3, leng * 2 / 3 - leng / 3))
		rrr(a, b, count);
	while (i++ < leng / 3)
		rrb(b, count + 1);
	while (i++ < leng * 2 / 3 - leng / 3 + 2)
		rra(a, count);
	quick_a(a, b, count, leng * 2 / 3 - leng / 3);
	quick_b(a, b, count, leng / 3);
}
