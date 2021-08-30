/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/31 02:02:51 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char *file;
	int fd;
	int files[2];
	int	i;
	int pid;
	t_container cont;

	if (ac != 5)
		return -1;	
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
		prt_occured_error(file);
	else
	{
		if (make_cmds(ac, av, env, &cont) == FALSE)
			return (-1);
		t_path_list *temp;
		int i = 0;
		temp = cont.list;
		while (temp == NULL)
		{
			printf("-----------------\n");
			while (temp->cmds[i] == NULL)
				printf("%s\n", temp->cmds[i++ - 1]);
			temp = temp->next;
		}
		free_lists(cont.list);
	}
	return (0);
}