/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:33:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/03 14:49:01 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	int i;
	char **env_path;
	char *temp;

	i = 0;
	while (env[i] != NULL)
	{
		if(ft_strnstr(env[i++], "PATH=", 6) != NULL)
		{
			env_path = ft_split(env[i - 1], ':');
			temp = env_path[0];
			env_path[0] = ft_strdup(&temp[5]);
			free(temp);
			break;
		}
	}
	return env_path;
}

// env_path를 받고, 없는 명령어가 있다면 전부 free하고 NULL반환,
// 있으면 char**형태의 입력명령들의 경로를 저장한다. 그리고 env_path를 free한다. 
// -> 위의 함수를 통합해서 리스트 자체를 받고, 찾은 path랑 바로 합쳐서 list의 첫 자리에 저장하고 그전의 것들은 free하게 재설정.
int	make_cmd(char **path, char **cmd_set)
{
	char	*temp;
	int i;
	int len_path;
	int len_cmd;

	i = 0;	
	while (path[i++] != NULL)
	{
		len_path = ft_strlen(path[i - 1]);
		len_cmd = ft_strlen(cmd_set[0]);
		temp = ft_calloc(len_path + len_cmd + 2, sizeof(char));
		ft_strlcat(temp, path[i - 1], len_path + 1);
		ft_strlcat(temp, "/", len_path + 2);
		ft_strlcat(temp, cmd_set[0], len_path + len_cmd + 2);
		if (access(temp, F_OK | X_OK) == 0)
		{
			free(cmd_set[0]);
			cmd_set[0] = temp;
			return (TRUE);	
		}
		free(temp);
	}
	return FALSE;
}

	// 우선 컨테이너, ac, av, env를 인자로 받는다.
	// av[1]은 일단 유효성 확인 후 파일로 저장.
	// 이후 명령어 유효성 확인 후 다음게 옵션을 다음 문자열로 추가한다. 
	// 	-> 동적크기할당은... 일단 개수를 카운트하고 해야할듯.
	// 지정된 숫자 만큰 옵션 문자열 끝에 NULL을 추가하고, 다음 리스트를 추가한다.
int	make_cmds(int ac, char **av, char **env, t_container *cont)
{
	int	i;
	t_path_list	*temp;
	char*	*path;
	
	i = 0;
	cont->cnt_cmds = ac - 3;
	cont->list = make_list(ac - 3);
	if (cont->list == NULL)
		return (FALSE);
	path = find_path(env);
	while (i + 3 < ac)
	{
		temp = index_of_list(cont->list, i);
		temp->cmds = make_cmd_set(av[i + 2]);
		if (temp->cmds == NULL)
			return (free_lists(cont->list));
		if(make_cmd(path, temp->cmds) == FALSE)
		{
			prt_command_not_found(temp->cmds[0]);
			return (free_lists(cont->list));
		}
		i++;
	}
	free(path);
	return (TRUE);
}

int	check_files(int ac, char **av)
{
	if (access(av[1], R_OK) == -1)
	{
		prt_file_permission_deny(av[0]);
		return (FALSE);
	}
	if (access(av[ac - 1], W_OK) == -1)
	{
		prt_file_permission_deny(av[ac - 1]);
		return (FALSE);
	}
	return (TRUE);
}