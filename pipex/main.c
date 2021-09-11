/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/11 23:45:51 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pinfo(t_pinfo *pinfo, int ac, char **av, char **env)
{
	int	i;

	pinfo->num = 0;
	pinfo->num_fds = ac - 3;
	pinfo->path = find_path(env);
	pinfo->infile = av[1];
	pinfo->outfile = av[ac - 1];
	pinfo->fds = (int **)malloc((ac - 3) * sizeof(int *));
	if (pinfo->fds == NULL)
		exit(1);
	i = 0;
	while (i + 3 < ac)
	{
		pinfo->fds[i] = (int *)malloc(2 * sizeof(int));
		if (pinfo->fds[i++] == NULL)
			exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pinfo	pinfo;

	if (ac < 4)
		return (0);
	else if (ac == 4)
		just_redirection(av, env);
	init_pinfo(&pinfo, ac, av, env);
	while (pinfo.num + 3 < ac)
	{
		pipe(pinfo.fds[pinfo.num]);
		pinfo.child_pid = fork();
		if (pinfo.child_pid != 0)
			break ;
		++pinfo.num;
	}
	if (pinfo.num + 3 == ac)
		last_child_process(&pinfo, av[2]);
	else if (pinfo.num == 1)
		first_child_process(&pinfo, av[ac - 2]);
	else if (pinfo.num == 0)
		shell_process(&pinfo);
	else
		child_processes(&pinfo, av[ac - pinfo.num - 1]);
	return (0);
}
