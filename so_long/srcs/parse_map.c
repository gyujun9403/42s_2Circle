/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:08:00 by gyeon             #+#    #+#             */
/*   Updated: 2021/10/20 17:56:26 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_list	*make_map(int fd)
{
	int		return_gnl;
	char	*temp_str;
	t_list	*temp;

	temp = ft_lstnew(NULL);
	get_next_line(fd, (char **)(&temp->content));
	while (1)
	{
		return_gnl = get_next_line(fd, &temp_str);
		if (return_gnl == -1)
		{
			ft_lstclear(&temp, free);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&temp, ft_lstnew(NULL));
			ft_lstlast(temp)->content = temp_str;
			if (return_gnl == 0)
				break ;
		}
	}
	return (temp);
}

t_list	*parse_map(char *file)
{
	int		fd;
	t_list	*result_gnl;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error();
	result_gnl = make_map(fd);
	close(fd);
	if (result_gnl == NULL)
		map_error();
	else if (check_map(result_gnl) == ERROR)
		map_error();
	return (result_gnl);
}
