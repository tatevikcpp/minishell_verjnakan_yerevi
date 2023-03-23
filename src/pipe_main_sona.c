#include "minishell.h"

void pipe_in_out(int i, t_data *data, int count, t_pipe *pipe)
{
	if (i == 0)
	{
			dup2(data->fd[i][1], STDOUT_FILENO); // sovorel
	}
	else if (i ==  count - 1)
	{	
		dup2(data->fd[i - 1][0], STDIN_FILENO);
	}				
	else
	{
		dup2( data->fd[i - 1][0], STDIN_FILENO);
		dup2(data->fd[i][1], STDOUT_FILENO);
	}
	int j = -1;
	while (++j < count)
	{
		close(data->fd[j][1]);
		close(data->fd[j][0]);
	}
	lsh_launch(data, pipe);
	exit(0);
}

void pipe_exec(t_data *data)
{
	int		i;
	int		count;
	t_pipe *tmp;

	i = 0;
	count = data->pipe_count;
	data->fd = malloc(sizeof(int [2]) * count); // qnnarkel with Hovsep
	while (i < count)
	{
		if(pipe(data->fd[i]) == -1)
		{
			printf("error\n");
			return ;   // mtacel
		}
		i++;
	}
	i = 0;
	tmp = data->pipe;
	while (i < count && tmp)
	{
		pid_t id = fork();
		if (id == -1)
			perror("Error: fork\n");
		if (id == 0)
		{
			pipe_in_out(i, data, count, tmp);			
		}
		tmp = tmp->next;
		i++;
	}
	int j = -1;
	while (++j < count)
	{
		close(data->fd[j][1]);
		close(data->fd[j][0]);
	}
	j = -1;
	while (++j < count)
	{
	// 	i = waitpid(-1, NULL, 0);
		wait(0); // poxel waitpid
	}
}