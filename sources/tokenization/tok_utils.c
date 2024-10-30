/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrkhach <anrkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:09:10 by anrkhach          #+#    #+#             */
/*   Updated: 2024/07/18 21:28:51 by anrkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenization.h"
#include "utils.h"
#include <stdlib.h>

void	tokens_types(t_token *token_list)
{
	t_token			*c;
	t_token_params	params;

	params.cmd_found = 0;
	params.redir = 0;
	c = token_list;
	while (c)
	{
		c->type = set_token_type(c->value, 0);
		if (c->type == ERROR)
			er_hp1("minishell : syntax error near unexpected token `",
				c->value, "'\n", 2);
		if (c->prev != NULL && c->type == WORD && op(c->prev->value, 0) > 0)
		{
			if (c->prev->type == IN_REDIR)
				c->type = FILEIN;
			if (c->prev->type == HERE_DOC)
				c->type = LIMITER;
			if (c->prev->type == OUT_REDIR)
				c->type = FILEOUT;
			if (c->prev->type == APPEND_REDIR)
				c->type = APPEND_FILEOUT;
		}
		c = c->next;
	}
}

int	is_pipe_or_dpipe(char *value, int i)
{
	if (value[i + 1] && value[i] == value[i + 1]
		&& syntx_err(value, i + 2) != 1)
		return (D_PIPE);
	if (syntx_err(value, i + 1) == 1)
		return (ERROR);
	return (S_PIPE);
}

int	is_and_or_dand(char *value, int i)
{
	if (value[i + 1] && value[i] == value[i + 1]
		&& syntx_err(value, i + 2) != 1)
		return (D_AND);
	if (syntx_err(value, i + 1) == 1)
		return (ERROR);
	return (S_AND);
}

int	is_append_or_out_redir(char *value, int i)
{
	if (value[i + 1] && value[i] == value[i + 1]
		&& syntx_err(value, i + 2) != 1)
		return (APPEND_REDIR);
	if (syntx_err(value, i + 1) == 1)
		return (ERROR);
	return (OUT_REDIR);
}

t_token_type	set_token_type(char *value, int i)
{
	if (!value || i < 0)
		return (ERROR);
	if (value[i] == '|')
		return (is_pipe_or_dpipe(value, i));
	else if (value[i] == '&')
		return (is_and_or_dand(value, i));
	else if (value[i] == '>')
		return (is_append_or_out_redir(value, i));
	else if (value[i] == '<')
	{
		if (value[i + 1] && value[i] == value[i + 1]
			&& syntx_err(value, i + 2) != 1)
			return (HERE_DOC);
		if (syntx_err(value, i + 1) == 1)
		{
			return (ERROR);
		}
		return (IN_REDIR);
	}
	return (WORD);
}
