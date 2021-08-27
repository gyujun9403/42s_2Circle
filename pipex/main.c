/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/27 01:14:25 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char *file;
	char **temp_strs;
	int fd;
	int files[2];
	int	i;
	int pid;
	char buff[PIPE_BUFFER_SIZE];

	//if (ac < 2)
	if (ac != 3)
		return -1;	
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
		prt_occured_error(file);
	else
	{
		i = 0;
		temp_strs = make_cmds(ac, av, env);
		//pipe(files);
		//pid = fork();
		// if (pid != 0) // 부모
		// {
			
		// }
		// else
		// {
			 
		// }

		char **temp;
		temp = ft_calloc(4, sizeof(char *));
		temp[0] = "/bin/ls";
		temp[1] = "-al";
		temp[2] = "../";
		//temp[1] = "./infile";
		temp[3] = NULL;
		execve(temp[0], temp, NULL);
		close(fd);
		free(temp);
	}
	return (0);
}