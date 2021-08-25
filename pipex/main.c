/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/25 17:37:52 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char *file;
	char **temp_strs;
	int fd;
	int	i;

	if (ac < 2)
		return -1;	
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
		prt_occured_error(file);
	else
	{
		i = 0;
		temp_strs = make_cmds(ac, av, env);
		if (temp_strs != NULL)
			while (temp_strs[i] != NULL) 
				printf("%s\n", temp_strs[i++]);
		close(fd);
	}
	return (0);
}