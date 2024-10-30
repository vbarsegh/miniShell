/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrkhach <anrkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:40:22 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/07/18 21:29:17 by anrkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"
# include "tokenization.h"
# include <stdbool.h>

char		*ft_substr(char const *s, unsigned int start,
				size_t len, bool is_op);
int			ft_isspace(char c);
int			op(char *s, int i);
int			ft_isalpha(int c);
size_t		ft_strlen(const char *s);
void		ft_token_list_clear(t_token **lst);
int			ft_strcmp(char *s1, char *s2);
void		dolarni2(t_token **tokens, t_env_elem *env, bool flag_a);
char		*ft_strjoin(char const *s1, char const *s2, char sep);
char		*join(char *s1, char *s2, size_t i, size_t j);
char		*ft_strdup(char *src);
char		*ft_strstr(char *str, char *to_find);

//spliti hamar
char		**ft_split(char const *s, char c);

//lst_func
t_env_elem	*ft_lstnew_dlya_env(char *key, char *value, bool will_free);
t_env_elem	*ft_lstlast(t_env_elem *lst);
void		ft_lstadd_back_env(t_env_elem **lst, t_env_elem *new);
int			ft_lstsize(t_env_elem *lst);
int			print_env(t_env_elem *env, int *is_builtin);

//check_syntax-i hamar
int			check_syntax(t_token *token);
int			permitted_operator(t_token *token);
int			control_operators(t_token *token);
int			syntx_err(char *value, int i);

//freee
void		free_list(t_env_elem *temp);
void		karch(char *value, int *i, int *j, bool *flag_a);
void		free_env(char **env);
char		**karch2(t_dollar *d, int start, int mid, int end);
void		karch3(char *p1, char **p, bool *flag);
void		clear_shell_envr(t_shell *shell);
void		free_temp_value(t_env_elem *temp);
void		free_shell_token(t_shell **shell,
				t_token **token_list, char *cmd_line);
void		free_key_and_value(char *key, char *value);
int			func_1(t_cmd *cmd, int *i, int *error_exit);
int			func_2(char *key, int *i, int *error_exit);

//chakertni
char		*begin_func(int j, char *value);
char		*word_func(int i, int j, char *value);
char		*end_func(int i, char *value);
int			i_func(char *begin, char *word);
void		free_func(char *begin, char *end, char *final, char *word);

#endif