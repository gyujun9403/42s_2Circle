/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:38:19 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/25 14:59:41 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

void	prt_command_not_found(char *str)
{
	char	*temp_str;
	int		str_len;

	str_len = ft_strlen(str);
	temp_str = ft_calloc(str_len + 29, sizeof(char));
	ft_strlcat(temp_str, "gyeon: ", 8);
	ft_strlcat(temp_str, str, 8 + str_len);
	ft_strlcat(temp_str, ": command not found\n", 29 + str_len);
	ft_putstr_fd(temp_str, STDERR_FILENO);
	free(temp_str);
}
