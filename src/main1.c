#include "minishell.h"


void printf_pipe(t_pipe *pipe)
{
	t_pipe *pipe_in;
	int i = 0;

	pipe_in = pipe;
	while (pipe_in)
	{
		printf("⛩  pipe [%d]\n", i++);
		int i = 0;
		print_list(pipe_in->red);
		printf("argv ***********************************\n");
		while (pipe_in->argv && pipe_in->argv[i])
		{
			printf("argv = %s, ", pipe_in->argv[i]);
			i++;
		}
		printf("\nfd_in %d, ", pipe_in->fd_in);
		printf("fd_out %d", pipe_in->fd_out);
		printf("\nargv ***********************************\n");
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
		// printf("%s\n", )
		if (*ptr == '\0')
			continue ;
		add_history(ptr);
		// function(&data, ptr);
		if (parsing(&data, ptr) != 0)
			continue ;
		// execute(&data, ptr);
		

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

