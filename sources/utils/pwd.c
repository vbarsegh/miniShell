/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrkhach <anrkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:50:59 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/07/22 19:15:29 by anrkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenization.h"
#include "utils.h"
#include "env.h"
#include "pipex.h"

int	pwd(int fd, int *is_builtin)
{
	char	current_directory[PATH_MAX];

	*is_builtin = 1;
	if (getcwd(current_directory, PATH_MAX) == NULL)
	{
		fd_put_string("minishell: can't read getcwd\n", fd);
		return (1);
	}
	fd_put_string(current_directory, fd);
	write (fd, "\n", 1);
	return (0);
}
