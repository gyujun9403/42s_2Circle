/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:51:01 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/03 14:51:21 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1
# define FREE_ONE 0
# define FREE_ALL 1
# define A 0
# define B 1
# define CASE1 1
# define CASE2 2
# define CASE3 3
# define CASE4 4
# define CASE5 5
# define CASE6 6
# define ERROR_CASE 0

typedef struct s_list
{
	struct s_list	*previous;
	struct s_list	*next;
	int				data;
}	t_list;

typedef struct s_container
{
	struct s_list	*start;
	struct s_list	*end;
	int				leng;
}	t_container;

/*
**	functions for setting list and utils
*/
char	*ps_atoi(char *str, int *num_container);
int		set_lists(t_container *container, int ac, char **av);
int		free_list(t_container *container, short flg);
int		compare_top_three(t_container *container);
void	command_hub(int command, t_container *a, t_container *b, int *count);
int		a_is_sorted(t_container *a, int check);
int		b_is_sorted(t_container *b, int check);
void	set_min_max(t_container *container);
int		find_smaller(int a, int b);
int		find_bigger(int a, int b);
void	element_swap(int *a, int *b);

/*
**	functions for operating stack
*/
void	pa(t_container *a, t_container *b, int *count);
void	pb(t_container *a, t_container *b, int *count);
void	sa(t_container *container, int *count);
void	sb(t_container *container, int *count);
void	ss(t_container *a, t_container *b, int *count);
void	ra(t_container *a, int *count);
void	rb(t_container *b, int *count);
void	rr(t_container *a, t_container *b, int *count);
void	rra(t_container *a, int *count);
void	rrb(t_container *b, int *count);
void	rrr(t_container *a, t_container *b, int *count);

/*
**	functions for sorting
*/
void	sort_two_a(t_container *a, int *count);
void	sort_two_b(t_container *a, t_container *b, int *count);

void	sort_just_three_a(t_container *a, int *count);
void	sort_just_three_b(t_container *a, t_container *b, int *count);

void	sort_top_three_a(t_container *a, int *count);
void	sort_top_three_b(t_container *a, t_container *b, int *count);

void	sort_four_a(t_container *a, t_container	*b, int *count);
void	sort_four_b(t_container *a, t_container	*b, int *count);

void	sort_five_a(t_container *a, t_container *b, int *count);
void	sort_five_b(t_container *a, t_container *b, int *count);

void	find_two_pivot(t_container *container, int leng, int *pivot);
void	quick_a(t_container *a, t_container *b, int *count, int leng);
void	quick_b(t_container *a, t_container *b, int *count, int leng);

#endif
