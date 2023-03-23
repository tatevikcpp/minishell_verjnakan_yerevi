#ifndef MINISHELL_H
# define MINISHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# define HEREDOC 5

# define METACHARACTER "|&;()<> \n\t"
# define METACHARACTER_ERROR "|&;)(<>"

typedef struct s_redirect
{
	int	flag;  // O_APPEND || O_TRUNC || O_RDONLY || HEREDOC
	char *f_name;
	char *flag_tmp;
	struct s_redirect *next;
} t_redirect;

typedef struct s_env
{
	char 			*key;
	char 			*val;
	struct s_env	*next;
}t_env;

typedef struct s_pipe
{
	char			*s;
	char			*content; // free
	int				fd_in;  // 0
	int				fd_out; // 1
	char			**argv; // null // free
	t_redirect		*red; // null
	t_env			*head_env;  // data->env;
	struct s_pipe	*next;  // null
}	t_pipe;



typedef struct s_data
{
	int		(*fd)[2]; // read-0 write-1
	t_env	*head_env;
	char	**env; // update env after export and unset
	// char	**splited_pipe;
	t_pipe 	*pipe;
	int		pipe_count;
	int 	fd_herdoc; // sxal anun
}	t_data;


//***********************Tatev


char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char const	*s, unsigned int start, size_t len);
char 		*ft_get_value(char *key, t_data *ptr);
// int  herdoc(int c, char **v);
t_redirect	*redirect(t_pipe *pipe);
//***************** Tatev

bool		is_space(char c);
bool    	is_pipe(char c);
bool    	is_redirect_in(char c);
bool    	is_redirect_out(char c);
bool    	is_append_in(char c, char d);
bool    	is_append_out(char c, char d);
char		*valid_ls(char *str);
// t_pipe *get_pipe_readline(t_data *data);
void		split_string(char *input, t_data *data);
// void print_list(t_redirect *red);
void 		print_list_head_env(t_data *data);
void 		print_lists(t_pipe *red);
int 		get_readline(t_data *data);
int 		init(t_data	*data, char **envp);
void		ft_lstadd_back(t_pipe **lst, t_pipe *new);
void		ft_lstadd_front(t_pipe **lst, t_pipe *new);
t_pipe		*ft_lstnew(void *content, t_env *env);
t_pipe		*ft_lstlast(t_pipe *lst);
int 		check_quot_double(char *ptr);
char 		*check_quot_one(char *ptr);
void		struct_zeroed(t_data *data, char **env);
int  		for_space(char *ptr, char c, int i);
int  		for_space_quot(char *ptr, char c, int *i);
void 		send_env(t_data *data);
// void 		send_env(t_pipe *data);

void 		print_env(t_data *data);
// void	print_env(t_pipe *data);
void 		print_list(t_redirect *red);

//
char			*split_quote(char *top, int *i, char c);
void			ft_t_redirect_add_back(t_redirect **lst, t_redirect *new);
t_redirect		*ft_t_redirect_last(t_redirect *lst);
// t_redirect 		*new_t_redirect(char *f_name, char *flag);

int		redirect_f_name_flag(t_pipe *top,t_redirect **head, int *i);
int		redirect_to_command(t_pipe *top, int *i) ;
void	redirect_to_quote(t_pipe *top, int *i, char c);
// char *redirect_to_quote(t_pipe *top, int *i, char c);

void	ft_t_pipe_add_back(t_pipe **lst, t_pipe *new);
t_pipe *new_t_pipe(char **tmp);
t_pipe	*ft_t_pipe_last(t_pipe *lst);

char *hendl_dolar(t_pipe *data, char *str, int *i);
char *hendl_doloar_comand(t_pipe *data, char *test, int *i);
char 		*get_dolar_val(t_pipe *data, char *str1);
void	split_s__to_argv(/* t_data *data,  */t_pipe *pipe);

//lkejfnlwjflka

int	syntax_error(char *ptr, int *i);
int	metachar_error(char *ptr);
// void split_s__to_argv(t_pipe *pipe);

//Added by Amalia 
int check_qoutes(char *str);

///sevagrutyun

/* char *hendl_doloar_comand(t_data *data, char *test);
void hendl_dolar(t_data *data, char *str);
char *get_dolar_val(t_data *data, char *str1); */

void print_list_head_env_pipe(t_pipe *pipe);

//----------------------------------------

char *hendl_export_var(char *str1);
void buildin_export_all(t_data *data/* , char *ptr */);
void buildin_export_all_by_alphabet(t_data *data);
void buildin_export_all_by_alphabet_inner(t_data *data);
void buildin_env_all(t_data *data);
void unset_buildin(t_data *data, char *ptr);
void ft_list_remove_if(t_data *data,/*  void *data_ref,  */int (*cmp)(), char *ptr);
void remove_else_inner(t_data *data,int (*ft_strcmp)(), char **str1);
void remove_if_inner(t_data *data, int (*ft_strcmp)(), char *str);
int check_symbol(char *str);
int ft_cd(char *str, t_data *data);
void    ft_echo(char **ptr);
int is_digit(char *str);
int is_char(char *str);
void	max_int(char *str, t_data *data);
int	neg_to_pos(long double nbr);
int ft_exit(char **str, t_data *data);
int    ft_pwd(void);
// char *heredoc(char *str,  t_data *data);
void heredoc(char *ptr,t_data *data);
// char * append_redir(char *ptr);
void append_red(/* t_data *data */);
void choose_redirect(t_data *data, char *ptr);


t_redirect		*ft_t_redirect_last(t_redirect *lst);
void		ft_t_redirect_add_back(t_redirect **lst, t_redirect *new);
t_redirect *new_t_redirect(char *f_name, char *flag_tmp, int flag);

// void	redirect_f_name_flag(t_pipe *top,t_redirect **head, int *i);
// void	redirect_to_command(t_pipe *top, int *i) ;

t_pipe *new_t_pipe(char **tmp);
t_pipe	*ft_t_pipe_last(t_pipe *lst);
void	ft_t_pipe_add_back(t_pipe **lst, t_pipe *new);

// void hendl_dolar(t_data *data, char *str);
// char *hendl_dolar_inline(t_data *data, char *str);

void builtin_export(t_data *data, char *ptr);
// void split_readline(char *ptr,/* t_pipe *pipe, */ t_data *data);
void split_readline(char *ptr , t_pipe *pipe, t_data *data);

t_env 	*new_t_env(char *tmp, char* tmp1);
t_env	*ft_t_env_last(t_env *lst);
void	ft_t_env_add_back(t_env **lst, t_env *new);

//--------------------------------------------
void pipe_exec(t_data *data);
int lsh_launch(t_data *data, t_pipe *pipe);
int ther_is_buildin(t_data *data, char *ptr);
t_redirect	*redirect_test(t_pipe *pipe);


//
int parsing(t_data *data, char *ptr);
void execute(t_data *data, char *ptr);

#endif
