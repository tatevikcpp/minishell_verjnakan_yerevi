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
	// while (i < 10)
	// {
	// 	ptr = malloc(1);
	// }
	
	struct_zeroed(&data, env); // jamanakavor
	while (1)
	{

		// print_list_head_env(&data);
		ptr = readline("minishell-$ ");
		if (ptr == NULL)
			exit(1);
		// printf("%s\n", )
		if (*ptr == '\0')
			continue ;
		add_history(ptr);
		// function(&data, ptr);
		// if (check_errors(ptr) != 0)
		// 	continue ;
		if (parsing(&data, ptr) != 0)
			continue ;
		// TODO check cmd existence
		execute(&data);
		free_data(&data);
		free(ptr);
// //------------------------------------------- Sona
		
// 		// heredoc(ptr,&data);
// 		// append_red();
// 		// choose_redirect(&data,ptr);
// 		// pipe_exec(&data);
// 		// append_redir(ptr);
// //------------------------------------------- Sona	


// 		// print_list_head_env(data.head_env);	
// 		// print_env(&data);
// 		// print_list(data.pipe);
// 		//////**************************
// 		// hendl_dolar(&data, ptr);
// 		// printf("comand : %s\n", hendl_doloar_comand(&data, ptr));
// 		///////////////************************

// 		// send_env(&data);
		 	
// 		// 	data.pipe
// 		// exit(1);
// 		// printf("ok\n");

	}
// t_pipe *head = get_pipe_readline(&data, ptr);
	return (0);
}

