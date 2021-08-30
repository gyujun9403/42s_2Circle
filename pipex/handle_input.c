/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:33:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/08/30 15:16:46 by gyeon            ###   ########.fr       */
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
char	*check_cmd(char **path, char *cmd)
{
	char	*temp;
	int i;
	int len_path;
	int len_cmd;

	i = 0;	
	while (path[i++] != NULL)
	{
		len_path = ft_strlen(path[i - 1]);
		len_cmd = ft_strlen(cmd);
		temp = ft_calloc(len_path + len_cmd + 2, sizeof(char));
		ft_strlcat(temp, path[i - 1], len_path + 1);
		ft_strlcat(temp, "/", len_path + 2);
		ft_strlcat(temp, cmd, len_path + len_cmd + 2);
		if (access(temp, F_OK | X_OK) == 0)
		{
			return (temp);
			break ;
		}
		free(temp);
	}
	return NULL;
}

char	*check_pathcmd(char *pathcmd)
{		
	if (access(pathcmd, F_OK | X_OK) == 0)
		return (pathcmd);
	return NULL;
}

//char	**make_cmds(int ac, char **av, char **env)
int	make_cmds(int ac, char **av, char **env, t_container *cont)
{
	int	i;
	char	**env_path;
	char	**cmds;

	// i = 1;
	// cmds = ft_calloc(ac - 1, sizeof(char*));
	// env_path = find_path(env);
	// while (i++ + 1 < ac)
	// {
	// 	if (av[i][0] == '/')
	// 		cmds[i - 2] = check_pathcmd(av[i]);
	// 	else
	// 		cmds[i - 2] = check_cmd(env_path, av[i]);
	// 	if (cmds[i - 2] == NULL)
	// 	{
	// 		free_strs(env_path);
	// 		free_strs(cmds);
	// 		prt_command_not_found(av[i]);
	// 		return NULL;
	// 	}
	// }
	// free_strs(env_path);
	
	// 우선 컨테이너, ac, av, env를 인자로 받는다.
	// av[1]은 일단 유효성 확인 후 파일로 저장.
	// 이후 명령어 유효성 확인 후 다음게 옵션을 다음 문자열로 추가한다. 
	// 	-> 동적크기할당은... 일단 개수를 카운트하고 해야할듯.
	// 지정된 숫자 만큰 옵션 문자열 끝에 NULL을 추가하고, 다음 리스트를 추가한다.
	int	i;
	int	cnt_option;
	t_list	*temp;
	
	if (access(av[1], F_OK | R_OK) != 0)
		return (FALSE);
	cont->file = av[1];
	i = 0;
	cnt_option = 0;
	cont->list = make_list(ac - 2);
	if (cont->list == NULL)
		return (FALSE);
	while (i + 2 < ac)
	{
		temp = index_of_list(cont->list, i);
		temp->content = make_cmd_set(av[i + 2]);
	}
}