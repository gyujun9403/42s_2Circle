/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:02 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/08 18:24:14 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void prt_cmd_set(char **cmd_set)
{
	int i = 0;

	while (cmd_set[i] != NULL)
		printf("\t%s\n", cmd_set[i++]);
}

int	main(int ac, char **av, char **env)
{
// 	char *file;
// 	int **fd;
// 	int files[2];
// 	int	i;
// 	int pid;
// 	t_container cont;

// 	if (ac < 3)
// 		return (-1);
// 	//if (check_files(ac, av) == FALSE)
// //		return (-1);
// 	cont.files[0] = av[1];
// 	cont.files[1] = av[ac - 1];
// //	fd = open(cont.files[0], O_RDONLY);
// //	if (fd == -1)
// //		prt_occured_error(file);
// 	if (make_cmds(ac, av, env, &cont) == FALSE)
// 		return (-1);
// 	if (make_cmd(path, temp->cmds) == FALSE)
// 	{
// 		prt_command_not_found(temp->cmds[0]);
// 		return (free_lists(cont->list));
// 	}
	
// 	free_lists(cont.list);
// 	close(fd);

	int	temp_fd;
	int	**fds;
	int	stat_loc;
	int	num;
	int pid;
	char	**path;
	char	**cmd_set;
	char	buffer[PIPE_BUFFER_SIZE];
	
	if (ac < 4)
		return (0);
	else if (ac == 4)
		return (0); //Not pipe, but fork and exec
	num = 0;
	path = find_path(env);
	fds = (int **)malloc((ac - 3) * sizeof(int *));
	while (num + 3 < ac)
	{
		fds[num] = (int *)malloc(2 * sizeof(int));
		pipe(fds[num]);
		printf("%dth pipe connected\n", num);
		pid = fork();
		if (pid != 0)
			break ;
		++num;
	}
	if (num + 3 == ac) // 가장 자식 프로세스
	{
		// 마지막 프로세서이므로, 이전 num에서 만든걸 써야한다.
		temp_fd = open(av[1], O_RDONLY);
		if (temp_fd == -1)
		{
			perror(av[1]);
			exit(1);
		}
		cmd_set = make_cmd_set(av[2]);
		if (make_cmd(path, cmd_set) == FALSE)
		{
			prt_command_not_found(cmd_set[0]);
			exit(1);
		}
		printf("last is %d in %d\n", num ,ac);
		// prt_cmd_set(cmd_set);
		dup2(temp_fd, STDIN_FILENO);
		dup2(fds[num - 1][1], STDOUT_FILENO);
		//int temp_fd2 = open(av[ac - 1], O_WRONLY);
		//dup2(temp_fd2, STDOUT_FILENO);
		//execve(cmd_set[0], cmd_set, NULL);
		read(STDIN_FILENO, buffer, PIPE_BUFFER_SIZE);
		printf("%s", buffer);
	}
	else if (num == 1) // 가장 부모의 자식 프로세스. 마지막 파일 및 명령문 처리
	{
		waitpid(pid, &stat_loc, 0);
		temp_fd = open(av[ac - 1], O_WRONLY);
		if (temp_fd == -1)
		{
			perror(av[ac - 1]);
			exit(1);
		}
		cmd_set = make_cmd_set(av[ac - 2]);
		if (make_cmd(path, cmd_set) == FALSE)
		{
			prt_command_not_found(cmd_set[0]);
			exit(1);
		}
		if (WEXITSTATUS(stat_loc) != 0)
		{
			//printf("%d child prossess false!\n", pid);
			exit(1);
		}
		printf("front is %d in %d\n", num ,ac);
		prt_cmd_set(cmd_set);
		dup2(fds[num][0], STDIN_FILENO);
		dup2(temp_fd, STDOUT_FILENO);
		// execve(cmd_set[0], cmd_set, NULL);
		read(STDIN_FILENO, buffer, PIPE_BUFFER_SIZE);
		printf("%s", buffer);
	}
	else if (num == 0) // 가장 부모 프로세스
	{
		waitpid(pid, &stat_loc, 0);
		if (WEXITSTATUS(stat_loc) == 0)
			printf("%d child prossess done!\n", pid);
		else
		{
			printf("%d child prossess false!\n", pid);
			exit(1);
		}
		printf("my num is %d in %d\n", num ,ac);
	}
	else // 이외 모든 프로세스
	{
		printf("I'm waiting %d\n", pid);
		waitpid(pid, &stat_loc, 0);
		printf("%d is done\n", pid);
		cmd_set = make_cmd_set(av[ac - num - 1]);
		if (make_cmd(path, cmd_set) == FALSE)
		{
			prt_command_not_found(cmd_set[0]);
			exit(1);
		}
		if (WEXITSTATUS(stat_loc) != 0)
		{
			//printf("%d child prossess false!\n", pid);
			exit(1);
		}
		printf("my num is %d in %d\n", num ,ac);
		//prt_cmd_set(cmd_set);
		dup2(fds[num][0], STDIN_FILENO);
		dup2(fds[num - 1][1], STDOUT_FILENO);
		execve(cmd_set[0], cmd_set, NULL);
		//read(STDIN_FILENO, buffer, PIPE_BUFFER_SIZE);
		//printf("%s", buffer);
	}

	return (0);
}