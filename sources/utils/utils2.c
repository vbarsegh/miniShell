/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrkhach <anrkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:10:48 by anrkhach          #+#    #+#             */
/*   Updated: 2024/07/18 21:29:23 by anrkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenization.h"
#include "utils.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int	op(char *s, int i)
{
	int	op_len;

	if (s[i] == '|' || s[i] == '&' || s[i] == '>' || s[i] == '<')
	{
		if (s[i + 1] && s[i] == s[i + 1])
			op_len = 2;
		else
			op_len = 1;
	}
	else
		op_len = 0;
	return (op_len);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len, bool is_op)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return ("");
	if (is_op == true)
		len = len - start;
	if (len <= ft_strlen(s))
		str = (char *) malloc(sizeof(char) * (len + 1));
	else
		str = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
