/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrkhach <anrkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:09:39 by anrkhach          #+#    #+#             */
/*   Updated: 2024/07/24 20:36:21 by anrkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenization.h"
#include "utils.h"
#include "env.h"
#include "pipex.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	check_num_is_valid(const char *str, unsigned long long nbr, int sign)
{
	if (nbr > (unsigned long long)LLONG_MAX + (unsigned long long)sign)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_exit_status = 255;
		exit (g_exit_status);
	}
}

long	ft_atoll(char *str, int sign)
{
	size_t				i;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		++i;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > LLONG_MAX)
			check_num_is_valid(str, nbr, sign);
		++i;
	}
	if (str[i])
		esel_senc(str);
	if (sign)
		return (-nbr);
	return (nbr);
}

void	esel_senc(char *str)
{
	printf("exit\n");
	g_exit_status = 255;
	er_hp1("minishell: exit: ", str,
		": numeric argument required\n", g_exit_status);
	exit(g_exit_status);
}
