/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:21:58 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/25 15:01:16 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_pinfo
{
	int		num;
	int		child_pid;
	int		num_fds;
	int		**fds;
	char	**path;
	char	**env;
	char	*infile;
	char	*outfile;
}	t_pinfo;

void	prt_command_not_found(char *str);
char	**make_cmd_set(char *cmd);
char	**check_inner_string(char **cmd_set);
char	**find_path(char **env);
int		make_cmd(char **path, char **cmd_set);
char	**check_and_set_cmds(t_pinfo *pinfo, char *cmd_chunk);
void	openfile_and_dup(char *file, int mode);
void	just_redirection(char **av, char **env);
void	last_child_process(t_pinfo *pinfo, char *cmd_chunk);
void	first_child_process(t_pinfo *pinfo, char *cmd_chunk);
void	child_processes(t_pinfo *pinfo, char *cmd_chunk);
void	shell_process(t_pinfo *pinfo);
int		free_arrs(char **arrs);
int		cmds_len(char **cmds);
int		find_char(char *str, char c);
char	**dump_new_string(char **cmd_set, int st, int end);
#endif