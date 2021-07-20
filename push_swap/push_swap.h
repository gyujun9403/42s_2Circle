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
# define PA 0
# define PB 1
# define SA 2
# define SB 3
# define SS 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
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
	int				min;
	int				max;
	int				leng;
}	t_container;


void	show_list(t_container *container);

char	*ps_atoi(char *str, int *num_container);
int		set_lists(t_container *container, int ac, char **av);
int		free_list(t_container *container, short flg);
int		compare_top_three(t_container *container);
void	command_hub(int command, t_container *container_a, t_container *container_b, int *count);
int		a_is_sorted(t_container *container_a, int check);
int		b_is_sorted(t_container *container_b, int check);
void	set_min_max(t_container *container);

/*
**	functions for operating stack
*/
void	pa(t_container *container_a, t_container *container_b, int *count);
void	pb(t_container *container_a, t_container *container_b, int *count);
void	sa(t_container *container, int *count);
void	sb(t_container *container, int *count);
void	ss(t_container *container_a, t_container *container_b, int *count);
void	ra(t_container *container_a, int *count);
void	rb(t_container *container_b, int *count);
void	rr(t_container *container_a, t_container *container_b, int *count);
void	rra(t_container *container_a, int *count);
void	rrb(t_container *container_b, int *count);
void	rrr(t_container *container_a, t_container *container_b, int *count);

void	sort_two_a(t_container *container_a, int *count);
void	sort_two_b(t_container *container_b, int *count);
void	sort_just_three_a(t_container *container_a, int *count);
void	sort_just_three_b(t_container *container_b, int *count);

void	sort_top_three_a(t_container *container_a, int *count);
void	sort_top_three_b(t_container *container_b, int *count);

void	quick_sort(t_container *a, t_container *b, int *count);
void	quick_a(t_container *a, t_container *b, int *count, int leng);
void	quick_b(t_container *a, t_container *b, int *count, int leng);

#endif
