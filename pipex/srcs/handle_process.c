/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:25:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/24 20:27:43 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	just_redirection(char **av, char **env)
{
	int		pid;
	int		stat_loc;
	char	**cmd_set;
	t_pinfo	pinfo;

	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, &stat_loc, 0);
		if (WEXITSTATUS(stat_loc) != 0)
			exit(WEXITSTATUS(stat_loc));
		printf("hi\n");
		exit(0);
	}
	pinfo.path = find_path(env);
	openfile_and_dup(av[1], O_RDONLY);
	openfile_and_dup(av[3], O_WRONLY | O_TRUNC | O_CREAT);
	cmd_set = check_and_set_cmds(&pinfo, av[2]);
	if (execve(cmd_set[0], cmd_set, env) == -1)
	{
		free_arrs(cmd_set);
		exit(1);
	}
}

void	last_child_process(t_pinfo *pinfo, char *cmd_chunk)
{
	char	**cmd_set;

	openfile_and_dup(pinfo->infile, O_RDONLY);
	cmd_set = check_and_set_cmds(pinfo, cmd_chunk);
	dup2(pinfo->fds[pinfo->num - 1][1], STDOUT_FILENO);
	if (execve(cmd_set[0], cmd_set, pinfo->env) == -1)
	{
		free_arrs(cmd_set);
		exit(1);
	}
}

void	first_child_process(t_pinfo *pinfo, char *cmd_chunk)
{
	int		stat_loc;
	char	**cmd_set;

	waitpid(pinfo->child_pid, &stat_loc, WNOHANG);
	openfile_and_dup(pinfo->outfile, O_WRONLY | O_TRUNC | O_CREAT);
	cmd_set = check_and_set_cmds(pinfo, cmd_chunk);
	close(pinfo->fds[pinfo->num][1]);
	dup2(pinfo->fds[pinfo->num][0], STDIN_FILENO);
	if (execve(cmd_set[0], cmd_set, pinfo->env) == -1)
	{
		free_arrs(cmd_set);
		exit(1);
	}
}

void	child_processes(t_pinfo *pinfo, char *cmd_chunk)
{
	int		stat_loc;
	char	**cmd_set;

	waitpid(pinfo->child_pid, &stat_loc, WNOHANG);
	cmd_set = check_and_set_cmds(pinfo, cmd_chunk);
	close(pinfo->fds[pinfo->num][1]);
	dup2(pinfo->fds[pinfo->num][0], STDIN_FILENO);
	dup2(pinfo->fds[pinfo->num - 1][1], STDOUT_FILENO);
	if (execve(cmd_set[0], cmd_set, pinfo->env) == -1)
	{
		free_arrs(cmd_set);
		exit(1);
	}
}

void	shell_process(t_pinfo *pinfo)
{
	int	i;
	int	stat_loc;

	waitpid(pinfo->child_pid, &stat_loc, 0);
	i = 1;
	close(pinfo->fds[0][0]);
	close(pinfo->fds[0][1]);
	while (i < pinfo->num_fds)
		close(pinfo->fds[i++][0]);
	if (WEXITSTATUS(stat_loc) != 0)
		exit(WEXITSTATUS(stat_loc));
	else
		exit(0);
}
