/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:54:43 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/11 00:22:20 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	openfile_and_dup(char *file, int mode)
{
	int result;

	result = open(file, mode);
	if (result == -1)
	{
		perror(file);
		exit(1);
	}
	if (mode == O_RDONLY)
	{
		if (dup2(result, STDIN_FILENO) == -1)
			exit(1);
	}
	else
	{
		if (dup2(result, STDOUT_FILENO) == -1)
			exit(1);
	}
	close(result);
}
