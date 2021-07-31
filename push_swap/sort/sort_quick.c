
#include "push_swap.h"

void find_two_pivot(t_container *container, int leng, int *pivot)
{
	int *temp_arr;
	t_list	*ptr;
	int i;
	int j;

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
		while (j + i + 1< leng)
		{
			if (temp_arr[j] > temp_arr[j + 1])
				element_swap(&temp_arr[j], &temp_arr[j + 1]);
			++j;
		}
		++i;
	}
	pivot[0] = temp_arr[(int)leng / 3];
	pivot[1] = temp_arr[(int)leng * 2 / 3];
	free(temp_arr);
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
	int cnt_ra;
	int	cnt_pb;
	int	cnt_pbrb;
	int	pivot[2];

	if (leng < 2)
	{
		// printf("a one\n");
		// write(1, "a : ", 4); show_list(a);
		// write(1, "b : ", 4); show_list(b);
		return ;
	}
	else if (leng == 2)
	{
		sort_two_a(a, count);
		// printf("a two\n");
		// write(1, "a : ", 4); show_list(a);
		// write(1, "b : ", 4); show_list(b);
		return ;
	}
	else if (leng == 3 && a->leng == 3)
	{
		sort_just_three_a(a, count);
		// printf("a three\n");
		// write(1, "a : ", 4); show_list(a);
		// write(1, "b : ", 4); show_list(b);
		return ;
	}
	else if (leng == 3)
	{
		sort_top_three_a(a, count);
		// printf("a top three\n");
		// write(1, "a : ", 4); show_list(a);
		// write(1, "b : ", 4); show_list(b);
		return ;
	}
	else if (a_is_sorted(a, leng) == TRUE)
	{
		// printf("a sorted\n");
		// write(1, "a : ", 4); show_list(a);
		// write(1, "b : ", 4); show_list(b);
		return ;
	}
	else if (leng == 5)
	{
		return (sort_five_a(a, b, count));
	}
	i = 0;
	cnt_ra = 0;
	cnt_pb = 0;
	cnt_pbrb = 0;
	find_two_pivot(a, leng, pivot);
	while (i++ < leng)
	{
		if (a->end->data >= pivot[1])
		{
			ra(a, count);
			++cnt_ra;
		}
		else
		{
			if (a->end->data >= pivot[0])
			{
				pb(a, b, count);
				rb(b, count);
				++cnt_pbrb;
			}
			else
			{
				pb(a, b, count);
				++cnt_pb;
			}
		}
	}
	i = 0;
	while (i < find_smaller(cnt_ra, cnt_pbrb))
	{
		rrr(a, b, count);
		++i;
	}
	while (i < cnt_ra)
	{
		rra(a, count);
		++i;
	}
	while (i++ < cnt_pbrb)
		rrb(b, count);
	// printf("[quick a]\n");
	// printf("pivot0 : %d\n", pivot[0]);
	// printf("pivot1 : %d\n", pivot[1]);
	// printf("cnt_ra : %d\n", cnt_ra);
	// printf("cnt_pb : %d\n", cnt_pb);
	// printf("cnt_pbrb : %d\n", cnt_pbrb);
	// write(1, "a : ", 4); show_list(a);
	// write(1, "b : ", 4); show_list(b);
	quick_a(a, b, count, cnt_ra);
	quick_b(a, b, count, cnt_pbrb);
	quick_b(a, b, count, cnt_pb);
}

void	quick_b(t_container *a, t_container *b, int *count, int leng)
{
	//int chr;

	int	i;
	int cnt_rb;
	int	cnt_pa;
	int	cnt_para;
	int	pivot[2];

	if (leng == 1)
		return pa(a, b, count);
	else if (leng == 2)
	{	
		sort_two_b(a, b, count);
		// pa(a, b, count);
		// pa(a, b, count);
		return ;
	}
	else if (leng == 3 && b->leng == 3)
	{
		sort_just_three_b(a, b, count);
		// while (leng-- > 0)
		// 	pa(a, b, count);
		return ;
	}
	else if (leng == 3)
	{
		sort_top_three_b(a, b, count);
		// while (leng-- > 0)
		// 	pa(a, b, count);
		return ;
	}
	else if (b_is_sorted(b, leng) == TRUE)
	{
		while (leng-- > 0)
			pa(a, b, count);
		return ;
	}
	else if (leng == 5)
	{
		return (sort_five_b(a, b, count));
	}
	i = 0;
	cnt_rb = 0;
	cnt_pa = 0;
	cnt_para = 0;
	find_two_pivot(b, leng, pivot);
	while (i++ < leng)
	{
		if (b->end->data > pivot[1])
		{
			pa(a, b, count);
			++cnt_pa;
		}
		else
		{
			if (b->end->data > pivot[0])
			{
				pa(a, b, count);
				ra(a, count);
				++cnt_para;
			}
			else
			{
				rb(b, count);
				++cnt_rb;
			}
		}
	}
	i = 0;
	quick_a(a, b, count, cnt_pa);
	while (i < find_smaller(cnt_rb, cnt_para))
	{
		rrr(a, b, count);
		++i;
	}
	while (i < cnt_rb)
	{
		rrb(b, count);
		++i;
	}
	while (i++ < cnt_para)
		rra(a, count);
	// printf("[quick b]\n");
	// printf("pivot0 : %d\n", pivot[0]);
	// printf("pivot1 : %d\n", pivot[1]);
	// printf("cnt_rb : %d\n", cnt_rb);
	// printf("cnt_pa : %d\n", cnt_pa);
	// printf("cnt_para : %d\n", cnt_para);
	// write(1, "a : ", 4); show_list(a);
	// write(1, "b : ", 4); show_list(b);
	quick_a(a, b, count, cnt_para);
	
	quick_b(a, b, count, cnt_rb);
}