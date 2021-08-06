/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:59:33 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:13:18 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_return_b(t_container *a, t_container *b, int leng)
{
	if (leng <= 5)
	{
		if (leng == 1)
			pa(a, b);
		else if (leng == 2)
			sort_two_b(a, b);
		else if (leng == 3 && b->leng == 3)
			sort_just_three_b(a, b);
		else if (leng == 3)
			sort_top_three_b(a, b);
		else if (b_is_sorted(b, leng) == TRUE)
			while (leng-- > 0)
				pa(a, b);
		else if (leng == 4)
			sort_four_b(a, b);
		else if (leng == 5)
			sort_five_b(a, b);
		return (TRUE);
	}
	else
		return (FALSE);
}

void	divide_chunk_b(t_container *a, t_container *b, int leng)
{
	int	i;
	int	pivot[2];

	i = 0;
	find_two_pivot(b, leng, pivot);
	while (i++ < leng)
	{
		if (b->end->data >= pivot[1])
			pa(a, b);
		else
		{
			if (b->end->data >= pivot[0])
			{
				pa(a, b);
				ra(a);
			}
			else
				rb(b);
		}
	}
}

/* pa	-> leng - leng * 2 / 3
** para	-> leng * 2 / 3 - leng / 3
** rb	-> leng / 3
*/
void	quick_b(t_container *a, t_container *b, int leng)
{
	int	i;

	if (check_return_b(a, b, leng) == TRUE)
		return ;
	divide_chunk_b(a, b, leng);
	i = 0;
	quick_a(a, b, leng - leng * 2 / 3);
	while (i++ < find_smaller(leng / 3, leng * 2 / 3 - leng / 3))
		rrr(a, b);
	while (i++ < leng / 3)
		rrb(b + 1);
	while (i++ < leng * 2 / 3 - leng / 3 + 2)
		rra(a);
	quick_a(a, b, leng * 2 / 3 - leng / 3);
	quick_b(a, b, leng / 3);
}
