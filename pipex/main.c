/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/06 18:17:54 by gyeon            ###   ########.fr       */
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

	if (ac < 3)
		return -1;
	if (check_files(ac, av) == FALSE)
		return (-1);
	cont.files[0] = av[1];
	cont.files[1] = av[ac - 1];
	fd = open(cont.files[0], O_RDONLY);
	if (fd == -1)
		prt_occured_error(file);
	else
	{
		if (make_cmds(ac, av, env, &cont) == FALSE)
			return (-1);
		t_path_list *temp;
		int i = 0;
		temp = cont.list;
		while (temp != NULL)
		{
			i = 0;
			printf("-----------------\n");
			while (temp->cmds[i] != NULL)
				printf("%s\n", temp->cmds[i++]);
			temp = temp->next;
		}

		
		free_lists(cont.list);
		close(fd);
	}
	return (0);
}