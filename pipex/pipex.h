/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:58 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/06 14:41:23 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define PIPE_BUFFER_SIZE 1024

typedef	struct	s_path_list
{
	char **cmds;
	struct s_path_list	*next;
}	t_path_list;

typedef	struct	s_container
{
	int cnt_cmds;
	char *files[2];
	t_path_list *list;
}	t_container;

// char	**make_cmds(int ac, char **av, char **env);
int		make_cmds(int ac, char **av, char **env, t_container *cont);
void	prt_occured_error(char *str);
int	free_lists(t_path_list *list_start);
void	prt_command_not_found(char *str);
void	prt_file_permission_deny(char *str);
void	prt_no_such_file(char *str);
t_path_list	*make_list(int num);
t_path_list	*index_of_list(t_path_list *list_start, int index);
char	**make_cmd_set(char* cmd);
int	check_files(int ac, char **av);
char	**check_inner_string(char **cmd_set);


#endif