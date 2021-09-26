/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:38:19 by gyeon             #+#    #+#             */
/*   Updated: 2021/09/26 14:03:16 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

void	prt_command_not_found(char *str)
{
	char	*temp_str;
	int		str_len;

	str_len = ft_strlen(str);
	temp_str = ft_calloc(str_len + 28, sizeof(char));
	ft_strlcat(temp_str, "bash: ", 7);
	ft_strlcat(temp_str, str, 7 + str_len);
	ft_strlcat(temp_str, ": command not found\n", 28 + str_len);
	ft_putstr_fd(temp_str, STDERR_FILENO);
	free(temp_str);
}
