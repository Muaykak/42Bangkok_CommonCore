/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:24:26 by srussame          #+#    #+#             */
/*   Updated: 2025/07/02 04:07:38 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* minishell.h */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/ioctl.h>

typedef enum e_use_function
{
	FT_CD,
	FT_PWD,
	FT_ENV,
	FT_ECHO,
	FT_EXPORT,
	FT_UNSET,
	FT_EXIT,
}	t_use_function;

typedef enum e_redirect_type
{
	READ_FILE,
	HERE_DOC,
	WRITE_FILE,
	APPEND_FILE,
}	t_redirect_type;

typedef enum e_pipe_pos
{
	FIRST,
	MIDDLE,
	LAST
}	t_pipe_pos;

typedef struct s_redirect
{
	t_redirect_type		type;
	bool				expand;
	char				*value;
	struct s_redirect	*next;
}	t_redirect;

/*
this struct is init before run all process one node 
is mean one pipe and redirect can stack multiple redirect 
pid declare init is 0 and cmd is "malloc" of cmd 

Example
---
echo helllo world > b > c | cat Makefie | < b cat
---
process
	cmd	[[echo] [hello world]]
	redirect
		type	WRITE_FILE
		value	b
		next
	redirect
		type	WRITE_FILE
		value	c
		next	NULL
	pid 0
next
process
	cmd [[cat] [Makefile]]
	redirect
		NULL
	pid	0
next
process
	cmd	[[cat]]
	redirect
		type	READ_FILE
		value	b
		next	NULL
	pid	0
next	NULL
---
*/
typedef struct s_process
{
	char				**cmd;
	t_redirect			*redirect;
	t_pipe_pos			pipe_pos;
	pid_t				pid;
	struct s_process	*next;
}	t_process;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_word_type
{
	READ,
	HEREDOC,
	WRITE,
	APPEND,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	EXPAND,
	PIPE,
	WORD,
	NORMAL,
	NOTEXPAND,
	FORBIDDEN
}	t_word_type;

typedef struct s_word_struct
{
	t_word_type					word_type;
	char						*word;
	struct s_word_struct		*next_word;
	struct s_word_struct		*prev_word;
}	t_word_struct;

int								builtin(t_process *proc, bool child_flag);
int								len_arg(char **arg);
void							ft_chdir(char **arg, bool child_flag);
void							ft_echo(char **arg, bool child_flag);
void							ft_pwd(char **arg, bool child_flag);
void							ft_env(char **arg, bool child_flag);
void							ft_export(char **arg, bool child_flag);
void							ft_unset(char **arg, bool child_flag);
void							ft_exit(t_process *proc, bool child_flag);
bool							strnum_cmp_ismorethan(char *str, char *des);
int								convert_exit_code(char *strnum);
void							builtin_return(int return_value,
									bool child_flag);
void							ft_exit_builtin_return(int exit_code,
									bool child_flag);
char							**ft_split_keyvalue(char *env);
bool							export_error(char *arg);
bool							find_char(char *arg);
bool							check_first_char(char *arg);
char							*absolute_path(char **arg, bool home);
char							*arg_check(char **arg, char *thispath);

/* builtin.h */

/* env.h */

char							***env(void);
t_env							**get_t_env(void);
t_env							*new_env(char *key, char *value);
void							print_env(void);
void							print_env_list(void);
void							set_essential_env(void);
char							**ft_split_keyvalue(char *env);
void							free_split(char **temp);

void							env_initialize(char **env);
void							del_env_list(char *key);
void							add_env_list(char *key, char *value);
void							env_list_clear(void);
void							env_list_delone(t_env *node);
void							env_list_addback(t_env **env_list,
									t_env *new_node);
void							setup_shlvl(void);
char							*get_env_value(char *key);
t_env							*search_env(char *key);
void							set_env_array(void);

/* env.h */

/* exit.h */

int								*get_code(void);
bool							is_exit(int num);

/* exit.h */

/*parser.h*/

/*  NEW FUNCTION ADDED FROM SRUSSAME  2025-6-6 */
char							***line(void);
void							clear_line(void);

// MAIN FUNCTION
t_process						*parser(char **line);

// SUB-FUNCTION

bool							lexer(char *line,
									t_word_struct **word_struct_list);
bool							grammar_check(t_word_struct **list);
bool							expand(t_word_struct **word_list);
bool							expand_dollar_sign(t_word_struct *wordlist);
bool							remove_quotation(t_word_struct **wordlist);
void							remove_empty_expand(t_word_struct **wordlist);

t_process						*create_process_list(t_word_struct **wordlist);

// LOWER FUNCTION - Sub of the Sub function
void							check_heredoc_expand(t_word_struct *temp);
bool							forbidden_check(t_word_struct **list);
char							**split_newline(char *lineread);
bool							lexer_addtoken_pipe(unsigned int *i,
									t_word_struct **word_struct_list);
bool							lexer_addtoken_redirect(char *line,
									unsigned int *i,
									t_word_struct **word_struct_list);
void							lexer_moveto_notspace(char *line,
									unsigned int *i);
bool							lexer_addtoken_forbidden(char *line, \
unsigned int *i, t_word_struct **word_struct_list);

t_word_struct					*create_expand_list(t_word_struct *target);
char							*get_next_expand_word(char **word);

char							*get_env_dollar_value(char **word);
size_t							count_until_quote(char *word);

char							**get_new_cmd(t_word_struct *wordlist);
t_redirect						*get_redirect_list(t_word_struct *wordlist);

// Utility
bool							cat_all_catlist(t_word_struct **cat_list,
									t_word_struct *wordlist);
void							process_list_lstclear(t_process **process_list);

void							word_struct_lstclear(t_word_struct \
**word_struct_list);
t_word_struct					*word_struct_newnode(t_word_type type,
									char *word);
bool							word_struct_addback(t_word_struct **list,
									t_word_struct *new);
void							word_struct_lstdelone(t_word_struct *lst);
t_word_struct					*word_struct_lstlast(t_word_struct \
*list);
void							word_struct_joinlist(t_word_struct \
**target_list, t_word_struct *new_list);
void							word_struct_remove_from_list(t_word_struct \
*to_remove, t_word_struct **head);

void							clear_cmd_char(char ***cmd);

void							redirect_lstclear(t_redirect **list);

// Debugging
void							print_lexer_token(t_word_struct *list);
void							print_process_list(t_process *proc);

/*parser.h*/

/*process.h*/

void							process_v2(void);

t_process						**get_t_process(void);
int								ft_heredoc(t_redirect *redirect);
int								read_all_heredoc(t_process *proc);
void							clear_t_process(void);
bool							redirect(t_process *proc, bool child_flag);

void							run_process_child_proc(int *pipe_fd, t_process \
*proc, int *orig_fd, int prev_pipe_read);
void							ft_wait_proc(pid_t last_pid);
int								is_builtin_v2(t_process *proc);
void							update_cmd_env(char **cmd);
int								len_process(void);
void							cat_all_catlist_heredoc_sub1(size_t len,
									t_word_struct *cat_list, char *cat_string);
char							*get_dollar_value_heredoc(char **word);
char							*get_not_dollar_sign_heredoc(char **word);
bool							expand_heredoc_line(char **line);
size_t							count_len_all_list(t_word_struct *cat_list);
bool							is_directory(char *pathname);

# define HEREDOC_ERR "\nminishell: warning: here-document at line delimited \
by end-of-file (wanted `%s')\n"

/*process.h*/

/*minishell_signal.h*/

void							signal_minishell_mode_1(void);
void							signal_minishell_mode_heredoc(void);
void							set_default_signal(void);
void							signal_minishell_mode_wait(void);
void							signal_allignore(void);
int								*sigint_status(void);
void							sigint_handler_mode_heredoc(int signum);
void							sig_handler_mode_wait(int signum);
void							sigint_handler_mode_1(int signum);

/*minishell_signal.h*/

/*exec.h*/

/*
execute function
--paramiter
  --cmd
    --[[command] [any argument]]
  --env
    --for find $PATH

--execute failed
  --if it failed must trow erorr "bash: %s: No such file or directory"
    and use [clear function] that clearfunction you can config 
    for [any memory leak] basicly that function use for free [cmd] and [env]
    and last exit at 127 exit code.
*/
void							exec_v2(char **cmd, char **env);
char							*get_command_path(char **env);
char							*access_absolute(char *cmd, char *path);

/*exec.h*/

#endif
