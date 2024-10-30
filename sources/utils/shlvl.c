/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:45:48 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/07/22 14:46:42 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenization.h"
#include "utils.h"
#include "env.h"
#include "pipex.h"

int	check_cmd_line(char *cmd_line)
{
	int	i;

	i = 11;
	if (cmd_line[0] == '.' && cmd_line[1] == '/' && cmd_line[2] == 'm'
		&& cmd_line[3] == 'i' && cmd_line[4] == 'n'
		&& cmd_line[5] == 'i' && cmd_line[6] == 's' && cmd_line[7] == 'h'
		&& cmd_line[8] == 'e' && cmd_line[9] == 'l' && cmd_line[10] == 'l')
	{
		if (cmd_line[i] == '\0')
			return (1);
		while (cmd_line[i])
		{
			if (cmd_line[i] == 32)
				i++;
			else
				break ;
		}
		if (cmd_line[i])
			return (-1);
		return (1);
	}
	return (-1);
}

void	found_shlvl(t_env_elem *env)
{
	int			shlvl_num;
	t_env_elem	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "SHLVL") == 0)
		{
			shlvl_num = ft_atoi(tmp->value) + 1;
			free(tmp->value);
			tmp->value = ft_itoa(shlvl_num);
		}
		tmp = tmp->next;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	poc;
	int	count;

	poc = 1;
	i = 0;
	result = 0;
	count = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			poc = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (nptr[i++] - 48) + (result * 10);
	return (result * poc);
}
