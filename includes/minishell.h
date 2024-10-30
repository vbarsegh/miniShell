/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrkhach <anrkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:20:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/07/24 20:32:29 by anrkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <termios.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "tokenization.h"

# define RM "rm"
# define RF	"-rf"
# define HERE_DOC_FILE "hesa kjnjvem"
# define TERM_CODE_SHIFT 128

int							g_exit_status;

typedef struct s_env_elem	t_env_elem;
typedef struct s_cmd		t_cmd;

typedef struct s_cmd
{
	int		input;
	int		output;
	char	*cmd_path;
	char	**cmd_args;
	t_cmd	*next;
}	t_cmd;

typedef struct s_env_elem
{
	char		*key;
	char		*value;
	t_env_elem	*next;
	t_env_elem	*prev;
}	t_env_elem;

typedef struct s_shell
{
	t_env_elem	*envr;
	t_cmd		*cmds;
	bool		shlvl;
}	t_shell;

t_env_elem	*merge_sort(t_env_elem *begin_list, int (*cmp)());
t_env_elem	*ft_merge_sorted_list(t_env_elem *left, t_env_elem *right,
				int (*cmp)());
t_env_elem	*ft_env_elem_at(t_env_elem *begin_list, unsigned int nbr);
int			ft_env_elem_size( t_env_elem *begin_list);
void		set_singals(void);
void		*ft_memset(void *b, int c, size_t len);
void		choose_signal(void (*f), int flag);
void		ctrl_bckslash(void);
void		disable_echoctl(void);

int			er_hp1(char *s1, char *s2, char *s3, int exit_status);
char		*open_dollar(t_dollar *dollar, t_env_elem *env);
void		qt_check_for_dollar(t_dollar *dollar);
void		veragrum(char **begin, char **word, char **end, char **dollar);
void		init_dollar(t_dollar *dollar, t_token **list);
void		kp(t_dollar *dollar);
char		*open_dollar(t_dollar *dollar, t_env_elem *env);
int			ft_atoi(const char *nptr);
void		found_shlvl(t_env_elem *env);
int			check_cmd_line(char *cmd_line);

#endif