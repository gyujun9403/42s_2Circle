#include "push_swap.h"

int find_pivot(short ab, t_container *container, int *count)
{
	int	top_flg;
	int	top_of_second_flg;

	top_flg = FALSE;
	top_of_second_flg = FALSE;
	if (container->end->data == container->max || container->end->data == container->min)
		top_flg = TRUE;
	if (container->end->previous->data == container->max
		|| container->end->previous->data == container->min)
		top_of_second_flg = TRUE;
	if (top_flg == TRUE && top_of_second_flg == TRUE)
	{
		if (ab == A)
			rra(container, count);
		else
			rrb(container, count);
	}
	else if (top_flg == TRUE)
	{
		if (ab == A)
			sa(container, count);
		else
			sb(container, count);
	}
	return (container->end->data);
}

void	quick_sort(t_container *a, t_container *b, int *count)
{
	// a에서 시작, a에서는 피봇 포함 작은 거 남기고 b로 넘긴다
	// 이후 다시 a와 b로 재귀 되는데, a가 먼저 와서 피봇보다 작은걸 정렬 완료한다.
	// 재귀를 끊는 지점은 넘겨 받은 개수가 1개, 2개, 3개일때이다.
	// 재귀 명령문 이후는 넘겨준 개수 만큼 다시 가지고 온다.
	// 내 생각이 맞다면 가지고 오는 것 들은 재귀의 마법에 의해 연쇄적으로 정렬이 되었을 것이다...
	quick_a(a, b, count, a->leng);
}

void	quick_a(t_container *a, t_container *b, int *count, int leng)
{
	int	i;
	int	cnt_push;
	int	pivot;

	if (leng < 2)
		return ;
	else if (leng == 2)
		return (sort_two_a(a, count));
	else if (leng == 3)
		return (sort_top_three_a(a, count));
	else if (a_is_sorted(a, leng) == TRUE)
		return ;
	i = 0;
	cnt_push = 0;
	pivot = find_pivot(A, a, count);
	while (i++ < leng)
	{
		if (a->end->data > pivot)
		{
			pb(a, b, count);
			++cnt_push;
		}
		else
			if (a->end->previous->data != pivot)
			{
				ra(a, count);
			}
	}
	quick_a(a, b, count, leng - cnt_push);
	quick_b(a, b, count, cnt_push);
	while (cnt_push--)
		pa(a, b, count);
}

void	quick_b(t_container *a, t_container *b, int *count, int leng)
{
	int	i;
	int	cnt_push;
	int	pivot;

	if (leng < 2)
		return ;
	else if (leng == 2)
		return (sort_two_b(b, count));
	else if (leng == 3)
		return (sort_top_three_b(b, count));
	else if (b_is_sorted(b, leng) == TRUE)
		return ;
	i = 0;
	cnt_push = 0;
	pivot = find_pivot(B, b, count);
	while (++i < leng)
	{
		if (b->end->data < pivot)
		{
			pa(a, b, count);
			++cnt_push;
		}
		else
			if (b->end->previous->data != pivot)
			{
				rb(b, count);
			}
	}
	quick_b(a, b, count, leng - cnt_push);
	quick_a(a, b, count, cnt_push);
	while (cnt_push--)
		pb(a, b, count);
}