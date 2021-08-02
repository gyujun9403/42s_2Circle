/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:58:03 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/02 22:56:22 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_two_pivot(t_container *container, int leng, int *pivot)
{
	int		*temp_arr;
	t_list	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = container->end;
	temp_arr = (int *)malloc(leng * sizeof(int));
	while (i < leng)
	{
		temp_arr[i++] = ptr->data;
		ptr = ptr->previous;
	}
	i = 0;
	while (i < leng)
	{
		j = 0;
		while (j++ + i + 1 < leng)
			if (temp_arr[j - 1] > temp_arr[j])
				element_swap(&temp_arr[j - 1], &temp_arr[j]);
		++i;
	}
	pivot[0] = temp_arr[(int)leng / 3];
	pivot[1] = temp_arr[(int)leng * 2 / 3];
	free(temp_arr);
}

int	check_return_a(t_container *a, t_container *b, int *count, int leng)
{
	if (leng <= 5)
	{
		if (leng < 2)
			;
		else if (leng == 2)
			sort_two_a(a, count);
		else if (leng == 3 && a->leng == 3)
			sort_just_three_a(a, count);
		else if (leng == 3)
			sort_top_three_a(a, count);
		else if (a_is_sorted(a, leng) == TRUE)
			;
		else if (leng == 4)
			sort_four_a(a, b, count);
		else if (leng == 5)
			sort_five_a(a, b, count);
		return (TRUE);
	}
	else
		return (FALSE);
}

/* ra	-> leng - leng * 2 /3
** pbrb	-> leng * 2 / 3 - leng / 3
** pb	-> leng / 3
*/
void	divide_chunk_a(t_container *a, t_container *b, int *count, int leng)
{
	int	i;
	int	pivot[2];

	i = 0;
	find_two_pivot(a, leng, pivot);
	while (i++ < leng)
	{
		if (a->end->data >= pivot[1])
			ra(a, count);
		else
		{
			if (a->end->data >= pivot[0])
			{
				pb(a, b, count);
				rb(b, count);
			}
			else
				pb(a, b, count);
		}
	}
	i = 0;
	while (i++ < find_smaller(leng - leng * 2 / 3, leng * 2 / 3 - leng / 3))
		rrr(a, b, count);
	while (i++ < leng - leng * 2 / 3 + 1)
		rra(a, count);
}

void	quick_a(t_container *a, t_container *b, int *count, int leng)
{
	int	i;

	if (check_return_a(a, b, count, leng) == TRUE)
		return ;
	i = 0;
	divide_chunk_a(a, b, count, leng);
	quick_a(a, b, count, leng - leng * 2 / 3);
	quick_b(a, b, count, leng * 2 / 3 - leng / 3);
	quick_b(a, b, count, leng / 3);
}
