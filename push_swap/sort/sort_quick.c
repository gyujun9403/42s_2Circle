#include "push_swap.h"

int find_pivot(t_container *container, int leng)
{
	int				pivot;
	// 최대/최소값에서 평균을 내서, 그 차이가 가장 작은 값을 pivot으로 선정. <- 실패
	// 각 a, b에 2개/3씩만 남기는건 어떨까? a는 2/3번째로 큰 값을, b는 2/3번째로 작은 값을 피봇으로 잡으면 될 꺼 같은데..
	unsigned int 	interval;
	int				midian;
	int				i;
	t_list			*temp;

	interval = 4294967295;
	midian = (container->max + container->min) / 2;
	i = 0;
	temp = container->end;
	while (i++ < leng)
	{
		if (midian > temp->data)
		{
			if ((unsigned int)(midian - temp->data) < interval)
			{
				interval = midian - temp->data;
				pivot = temp->data;
			}
		}
		else
		{
			if ((unsigned int)(temp->data - midian) < interval)
			{
				interval = temp->data - midian;
				pivot = temp->data;
			}
		}
		temp = temp->previous;
	}
	
	/*int				i;
	int				max;
	int				min;
	t_list			*temp;

	i = 0;
	temp = container->end;
	max = -2147483648;
	min = 2147483647;
	if (ab == A)
	{
		while (i++ < leng)
		{
			if (temp->data != container->max && temp->data > max)
			{
				pivot = temp->data;
				max = temp->data;
			}
			temp = temp->previous;
		}
	}
	else
	{
		while (i++ < leng)
		{
			if (temp->data != container->min && temp->data < min)
			{
				pivot = temp->data;
				min = temp->data;
			}
			temp = temp->previous;
		}
	}*/
		
	return (pivot);
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
	else if (leng == 3 && a->leng == 3)
		return (sort_just_three_a(a, count));
	else if (leng == 3)
		return (sort_top_three_a(a, count));
	else if (a_is_sorted(a, leng) == TRUE)
		return ;
	i = 0;
	cnt_push = 0;
	pivot = find_pivot(a, leng);
	while (i++ < leng)
	{
		if (a->end->data < pivot)
		{
			pb(a, b, count);
			++cnt_push;
		}
		else
			ra(a, count);
	}
	i = 0;
	while (i++ < leng - cnt_push)
		rra(a, count);
	quick_a(a, b, count, leng - cnt_push);
	quick_b(a, b, count, cnt_push);
}

void	quick_b(t_container *a, t_container *b, int *count, int leng)
{
	int	i;
	int	cnt_push;
	int	pivot;

	if (leng == 1)
		return pa(a, b, count);
	else if (leng == 2)
	{	
		sort_two_b(b, count);
		pa(a, b, count);
		pa(a, b, count);
		return ;
	}
	else if (leng == 3 && b->leng == 3)
	{
		sort_just_three_b(b, count);
		while (leng-- > 0)
			pa(a, b, count);
		return ;
	}
	else if (leng == 3)
	{
		sort_top_three_b(b, count);
		while (leng-- > 0)
			pa(a, b, count);
		return ;
	}
	else if (b_is_sorted(b, leng) == TRUE)
	{
		while (leng-- > 0)
			pa(a, b, count);
		return ;
	}
	i = 0;
	cnt_push = 0;
	pivot = find_pivot(b, leng);
	while (i++ < leng)
	{
		if (b->end->data > pivot)
		{
			pa(a, b, count);
			++cnt_push;
		}
		else
			rb(b, count);
	}
	i = 0;
	while (i++ < leng - cnt_push)
		rrb(b, count);
	quick_a(a, b, count, cnt_push);
	quick_b(a, b, count, leng - cnt_push);
}