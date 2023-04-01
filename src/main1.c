#include "minishell.h"


int there_is_builtin(t_pipe *pipe)
{
	int i;
	char *build_in[] = {"cd", "echo", "pwd", "exit", "env", "unset", "export", NULL};

	i = 0;
	if (pipe->argv && pipe->argv[0])
	{
		while (build_in[i])
		{
			if (ft_strcmp(pipe->argv[0], build_in[i]) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

void sig_int(int sig_num)
{
	// (void)sig_num;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

void handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sig_int);

}

// ls |>b| >y|ls
int main(int ac,  char **av,  char **env)
{
	int		i;
	t_data	data;
	char	*ptr;

	ptr = NULL;
	i = 0;
	(void)(av + ac);
	struct_zeroed(&data, env); // jamanakavor
	while (1)
	{
		handle_signal();
		free_data(&data);
		free(ptr);
		set_term_attr(0);
		ptr = readline("minishell-$ ");
		set_term_attr(1);
		if (ptr == NULL && ft_printf(2, "exit\n"))
			exit(ft_atoi(get_dolar_val(&data, "?")));
		if (*ptr == '\0')
			continue ;
		add_history(ptr);
		if (check_errors(ptr) != 0 && add_exit_status_in_env(&data, 258))
			continue ;
		if (parsing(&data, ptr) != 0 && add_exit_status_in_env(&data, 1))
			continue ;
		if (data.pipe)
			add_exit_status_in_env(&data, execute(&data));
	}
	return (0);
}

