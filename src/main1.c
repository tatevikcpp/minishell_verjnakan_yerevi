#include "minishell.h"

int exit_status;

int there_is_builtin(t_data *data)
{
	int i;
	i = 0;

	char *build_in[] = {"cd", "echo", "pwd", "exit", "env", "unset", "export", NULL};
	while (build_in[i])
	{
		if (ft_strcmp(data->pipe->argv[0], build_in[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

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
		free_data(&data);
		free(ptr);
		ptr = readline("minishell-$ ");
		if (ptr == NULL)
			exit(1);
		if (*ptr == '\0')
			continue ;
		add_history(ptr);
		// if (check_errors(ptr) != 0)
		// 	continue ;
		if (parsing(&data, ptr) != 0 && add_exit_status_in_env(&data, 1))
			continue ;
		// TODO check cmd existence
		if (data.pipe && data.pipe->argv[0])
			add_exit_status_in_env(&data, execute(&data));
	}
	return (0);
}

