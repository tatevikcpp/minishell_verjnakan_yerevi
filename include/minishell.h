/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:35:51 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 20:48:46 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ---- Used Libraries ---- */
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <sys/ioctl.h>

/* ------------------------ */

/* ----- Constants ----- */
# define HEREDOC 5
# define METACHARACTER "|&;()<> \n\t"
# define METACHARACTER_ERROR "|&;)(<>"
# define SPACES " \n\t"
/* --------------------- */

// extern int g_signal_status;

/* ----- Structures ----- */
typedef struct s_redirect
{
	int					flag;
	char				*f_name;
	char				*f_name_backup;
	int					heredoc_fd;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_env
{
	char				*key;
	char				*val;
	struct s_env		*next;
}	t_env;

typedef struct s_pipe
{
	char				*joined_argv;
	char				*content;
	int					fd_in;
	int					fd_out;
	char				**argv;
	t_redirect			*red;
	t_env				*head_env;
	struct s_pipe		*next;
}	t_pipe;

typedef struct s_data
{
	int					pipe_fd;
	int					fd1[2];
	int					(*fd)[2];
	t_env				*head_env;
	char				**env;
	t_pipe				*pipe;
	int					pipe_count;
	int					len_key_sum;
	int					len_val_sum;
}	t_data;
/* ------------------ */

/* --------------- libft functions -------------------------------------- */
char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char const	*s, unsigned int start, size_t len);
char		*ft_strjoin_ft(char const *s1, char c);
/* ---------------------------------------------------------------------- */

/* ----------------------------- Parsing ------------------------------- */
int			parsing(t_data *data, char *ptr);
int			open_files_for_redirect(t_pipe *pipe);
char		*function(t_data *data, char *test);
void		func(char *test, int j);

/* ------------------------- new lists ----------------------------- */
/* ------- env list --------- */ /* t_env.c */
t_env		*new_t_env(char *tmp, char *tmp1);
t_env		*ft_t_env_last(t_env *lst);
void		ft_t_env_add_back(t_env **lst, t_env *new);
/* ---------------------------------------------------------------- */

/* --------- pipe list ------ */ /* t_pipe.c */
t_pipe		*ft_lstnew(void *content, t_env *env);
void		ft_lstadd_back(t_pipe **lst, t_pipe *new);
void		ft_lstadd_front(t_pipe **lst, t_pipe *new);
t_pipe		*ft_lstlast(t_pipe *lst);
t_pipe		*ft_t_pipe_last(t_pipe *lst);
t_pipe		*new_t_pipe(char **tmp);
void		ft_t_pipe_add_back(t_pipe **lst, t_pipe *new);
/* ----------------------------------------- */

/* -------- redirection list -------- */ /* t_redirect.c */
void		ft_t_redirect_add_back(t_redirect **lst, t_redirect *new);
t_redirect	*ft_t_redirect_last(t_redirect *lst);
t_redirect	*new_t_redirect(char *f_name, int flag);
// t_redirect 	*new_t_redirect(char *f_name, char *flag);
/* ----------------------------------------------------- */

/* ---------- initialize lists -------  */ /* init_stract.c */
int			init_env(t_data	*data, char **envp);
void		struct_zeroed(t_data *data, char **env);
char		*ft_get_value(char *key, t_data *ptr);
/* -------------------------------------------------------- */

/* --------- parsing utils ---------------- */
bool		is_space(char c);
bool		is_pipe(char c);
bool		is_redirect_in(char c);
bool		is_redirect_out(char c);
bool		is_append_in(char c, char d);
bool		is_append_out(char c, char d);
/* ---------------------------------------- */

/* ----------- Ktrtel yev daraknerum teghadrel ---------------------- */
void		split_string(char *input, t_data *data);
t_redirect	*redirect_test(t_pipe *pipe);
int			redirect_f_name_flag(t_pipe *top, t_redirect **head, int *i);
int			redirect_to_command(t_pipe *top, int *i);
void		redirect_to_quote(t_pipe *top, int *i, char c);
void		split_s__to_argv( t_data *data, t_pipe *pipe);
/* ----------------------------------------------------------------- */

/* ------ print for tests ---------- */
void		print_list_head_env(t_data *data);
void		print_lists(t_pipe *red);
void		print_list(t_redirect *red);
void		print_env(t_data *data);
void		printf_pipe(t_pipe *pipe);
void		print_list_head_env_pipe(t_pipe *pipe);
/* -------------------------------- */

/* ------------ quotes -------------- */
// int 		check_quot_double(char *ptr);
// char 		*check_quot_one(char *ptr);
int			for_space(char *ptr, char c, int i);
char		*split_quote(char *top, int *i, char c);
// int  		for_space_quot(char *ptr, char c, int *i);
// int check_qoutes(char *str);
/* --------------------------------- */

/* ------- $ expansion --------------- */
void		hendl_dolar(t_data *data, char *str);
char		*hendl_doloar_comand(t_data *data, char *test);
char		*get_dolar_val(t_data *data, char *str1);
char		*function(t_data *data, char *test);
/* ----------------------------------- */
/* ----------------------------------------------------------- */

/* ----------------- Execution ------------------------------- */
int			execute(t_data *data);

/* ------- Pipes ------- */ /* pipe_exec.c */
int			pipe_exec(t_data *data);
void		pipe_in_out(int i, t_data *data, t_pipe *pipe);
int			lsh_launch(t_data *data, t_pipe *pipe);
/* -------------------- */

/* -------  Redirections ------- */ /* --- redirections.c --- */
void		infile(t_redirect *red, t_pipe *pipe);
void		outfile(t_redirect *red, t_pipe *pipe);
// void 	heredoc(t_redirect *red);
int			heredoc(t_data *data, t_redirect *red);
void		append_red(t_redirect *red, t_pipe *pipe);
void		choose_redirect(t_pipe *pipe, t_redirect *red);
/* ------------------------------ */

/* ----------- syntax errors -------------- */
int			syntax_error(char *ptr, int i);
int			metachar_error(char *ptr);
int			check_errors(char *ptr);
int			pipe_error(char *ptr);
/* ---------------------------------------- */
/* ------------------------------------------------------- */

/* ------------------------ Built-ins -------------------- */
int			choose_builtin(t_pipe *pipe, t_data *data, int fd);
int			there_is_builtin(t_pipe *pipe);
int			ther_are_equal(char *ptr);

/* ------ export ------------ */ /* builtin_export.c */
int			builtin_export(t_pipe *pipe, int fd);
int			buildin_export_sort_by_alphabet(t_pipe *pipe);
char		**ft_split_for_export(char const	*s, char c);
char		*hendl_export_var(char *str1);
/* ----- export utils ------ */
// char		*hendl_export_var(char *str1);
void		buildin_export_all(t_pipe *pipe, int fd);
void		buildin_export_all_by_alphabet(t_pipe *pipe);
// void		buildin_export_all_by_alphabet_inner(t_pipe *pipe);
/* ------------------------- */
/* -------------------------------------------------- */

/* ------ echo ------------- */ /* echo.c */
void		ft_echo(char **ptr, int fd);
/* ----- echo utils -------- */
int			check_symbol(char **str, int *k);
/* -------------------------- */
/* -------------------------------------- */

/* -------- cd -------------- */ /* cd.c */
int			ft_cd(char **argv, t_data *data);
/* ------------------------------------- */

/* ---------- exit ----------- */ /* exit.c */
int			ft_exit(char **str, t_data *data);
/* ----- exit utils ----- */
int			is_digit(char *str);
int			is_char(char *str);
int			neg_to_pos(long double nbr);
/* ---------------------- */
/* ---------------------------------------- */

/* ----- pwd ------ */ /* pwd.c */
int			ft_pwd(int fd);
/* ---------------------------- */

/* --------- env ----------------------------------- */
void		buildin_env_all(t_pipe *pipe, int fd);
void		send_env(t_data *data); /* redirect.c */
/* ------------------------------------------------- */

/* ----- unset ------------- */ /* builtin_export.c */
// void unset_buildin(t_data *data, char *ptr);
/* -------- unset utils -------- */
int			ft_list_remove_if(t_pipe *pipe, int (*ft_strcmp)());
// void		remove_else_inner(t_pipe *pipe, int (*ft_strcmp)(), char **str1);
// void		remove_if_inner(t_data *data, int (*ft_strcmp)(), char *str);
/* ------------------------------ */
/* ------------------------------------------------ */
/* ------------------------------------------------------------- */

/* ------ Free ------ */
void		free_data(t_data *data);
int			free_matrix(char **str);
char		*ft_strjon_free_arg1(char *s1, char const *s2);
char		*ft_strjon_free_arg2(char const *s1, char *s2);
char		*ft_strjon_free_both(char *s1, char *s2);
/* ------------------ */
// int			add_exit_status_in_env(t_data *data, int status);
/* ---- Signals ---- */
void		set_term_attr(int on_off);
/* ----------------- */

#endif