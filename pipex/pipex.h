/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:58 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/11 01:27:10 by gyeon            ###   ########.fr       */
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
	int		**fds;
	char	**path;
	char	*infile;
	char	*outfile;
}	t_pinfo;

// char	**make_cmds(int ac, char **av, char **env);
//int		make_cmds(int ac, char **av, char **env, t_container *cont);
void	prt_occured_error(char *str);
void	prt_command_not_found(char *str);
void	prt_file_permission_deny(char *str);
void	prt_no_such_file(char *str);
char	**make_cmd_set(char* cmd);
int	check_files(int ac, char **av);
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
#endif