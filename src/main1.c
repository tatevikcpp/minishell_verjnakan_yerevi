#include "minishell.h"


void printf_pipe(t_pipe *pipe)
{
	t_pipe *pipe_in;

	pipe_in = pipe;
	while (pipe_in)
	{
		int i = 0;
		print_list(pipe_in->red);
		while (pipe_in->argv && pipe_in->argv[i])
		{
			printf("argv = %s\n", pipe_in->argv[i]);
			i++;
		}
		pipe_in = pipe_in->next;
	}
}

int ther_is_buildin(t_data *data,char *ptr)
{
	int i;
	i = 0;

	char *build_in[] = {"cd", "echo", "pwd", "exit", "env", "unset", "export", NULL};
	while (build_in[i])
	{
		if (data->pipe->argv[0] == build_in[i])
			return (1);
		i++;
	}
	return (0);
}


int main(int ac,  char **av,  char **env)
{
	(void)(av+ac);
	int i;
	t_data	data;
	char *ptr = NULL;
	i = 0;
	while (1)
	{
		struct_zeroed(&data, env); // jamanakavor
		// print_list_head_env(&data);
		ptr = readline("minishell-$ ");
		if (ptr == NULL)
			exit(1);
		// if (*ptr == '\0')
		// 	continue ;
		add_history(ptr);
		parsing(&data, ptr);
		// execute(&data, ptr);
		

//------------------------------------------- Sona
		
		// heredoc(ptr,&data);
		// append_red();
		// choose_redirect(&data,ptr);
		// pipe_exec(&data);
		// append_redir(ptr);
//------------------------------------------- Sona	


		// print_list_head_env(data.head_env);	
		// print_env(&data);
		// print_list(data.pipe);
		//////**************************
		// hendl_dolar(&data, ptr);
		// printf("comand : %s\n", hendl_doloar_comand(&data, ptr));
		///////////////************************

		// send_env(&data);
		 	
		// 	data.pipe
		// exit(1);
		// printf("ok\n");
	}
    	// t_pipe *head = get_pipe_readline(&data, ptr);
	return (0);
}

