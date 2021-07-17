#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# define FREE_ONE 0
# define FREE_ALL 1
# define FALSE 0
# define TRUE 1

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

char	*ps_atoi(char *str, int *num_container);
int		set_lists(t_container *container, int ac, char **av);
int		free_list(t_container *container, short flg);

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

#endif
