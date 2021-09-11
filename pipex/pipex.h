/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:58 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/11 23:44:20 by gyeon            ###   ########.fr       */
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

typedef	struct	s_pinfo
{
	int	num;
	int child_pid;
	int		num_fds;
	int		**fds;
	char	**path;
	char	*infile;
	char	*outfile;
}	t_pinfo;

void	prt_command_not_found(char *str);
char	**make_cmd_set(char* cmd);
char	**check_inner_string(char **cmd_set);
char	**find_path(char **env);
int	make_cmd(char **path, char **cmd_set);
char	**check_and_set_cmds(char **path, char *cmd_chunk);

void	openfile_and_dup(char *file, int mode);
void	just_redirection(char **av, char **env);
void	last_child_process(t_pinfo *pinfo, char *cmd_chunk);
void	first_child_process(t_pinfo *pinfo, char *cmd_chunk);
void	child_processes(t_pinfo *pinfo, char *cmd_chunk);
void	shell_process(t_pinfo *pinfo);
int	free_arrs(char **arrs);
int	cmds_len(char **cmds);
int	find_char(char *str, char c);
#endif