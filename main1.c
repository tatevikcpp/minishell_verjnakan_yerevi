#include "minishell.h"


void printf_pipe(t_pipe *pipe)
{
	t_pipe *pipe_in;

	pipe_in = pipe;
	while (pipe_in)
	{
		int i = 0;
		print_list(pipe->red);
		while (pipe->argv[i])
		{
			printf("argv = %s\n", pipe_in->argv[i]);
			i++;
		}
		pipe_in = pipe_in->next;
	}
}

int ther_is_buildin(t_data data,char *ptr)
{
	int i;
	i = 0;

	char *build_in[] = {"cd", "echo", "pwd", "exit", "env", "unset", "export", NULL};
	while (build_in[i])
	{
		if (data.pipe->argv[0] == build_in[i])
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
		struct_zeroed(&data, env);
		// print_list_head_env(&data);
		ptr = readline("minishell-$ ");
		if (ptr == NULL)
			exit(1);
		// if (*ptr == '\0')
		// 	continue ;
		add_history(ptr);
		// if (syntax_error(ptr, &i) == 1 || metachar_error(ptr) == 1 ) // >a     ev ls|ls | "|ls|"
		// 	continue ;
		// if (syntax_error(ptr, &i) == 1)
		// 	continue ;
		// if (metachar_error(ptr) == 1)
		// 	continue ;							// kara chlini
		// check_qoutes(ptr); // sxala ashxatum

		// check_quot_double(ptr);
		// check_quot_one(ptr);
		// print_list_head_env(&data);


		split_string(ptr, &data); // ls|ls | "|ls|"  sxala ashxatum
		// print_lists(data.pipe);

		t_pipe *tmp1 = data.pipe;
		while (tmp1)//pttvum e michpaipain taracutjunerov u juraqanchjuri hamar gtnum redirektnery u faili anuner@
		{
			tmp1->red = redirect_test(tmp1); // sxal ls>a>b
			split_s__to_argv(/* &data,  */tmp1);
			tmp1 = tmp1->next;
		}
		printf_pipe(data.pipe);
		printf("pipe count: %d\n", data.pipe_count);
		if (data.pipe_count > 1)
		{
			pipe_exec(&data);
		}
		else if(data.pipe_count == 1)
		{
			if (ther_is_buildin(data, ptr) == 0)
				split_readline(ptr, data.pipe, &data);
			else
			{
				pipe_exec(&data);
			}		
		}

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

