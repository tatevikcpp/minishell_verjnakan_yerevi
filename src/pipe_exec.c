/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:29:33 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/30 22:00:57 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pipe_in_out(int i, t_data *data, t_pipe *pipe)
{
	if (data->pipe_count == 1)
	{
		if (pipe->fd_in != 0)
			dup2(pipe->fd_in, STDIN_FILENO);
		if (pipe->fd_out != 1)
			dup2(pipe->fd_out, STDOUT_FILENO);
		lsh_launch(data, pipe);
		exit(0);
	}
	if (i == 0)
	{
		if (pipe->fd_in != 0)
			dup2(pipe->fd_in, STDIN_FILENO);
		if (pipe->fd_out != 1)
			dup2(pipe->fd_out, STDOUT_FILENO);
		else if (data->pipe_count > 1)
			dup2(data->fd[i][1], STDOUT_FILENO);
	}
	else if (i ==  data->pipe_count - 1)
	{
		if (pipe->fd_out != 1)
			dup2(pipe->fd_out, STDOUT_FILENO);
		if (pipe->fd_in != 0)
			dup2(pipe->fd_in, STDOUT_FILENO);
		else
			dup2(data->fd[i - 1][0], STDIN_FILENO);
	}				
	else
	{
		if (pipe->fd_in != 0)
			dup2(pipe->fd_in, STDOUT_FILENO);
		else
			dup2(data->fd[i - 1][0], STDIN_FILENO);
		if (pipe->fd_out != 1)
			dup2(pipe->fd_out, STDOUT_FILENO);
		else
			dup2(data->fd[i][1], STDOUT_FILENO);
	}
	i = -1;
	while (data->pipe_count > 1 && ++i < data->pipe_count)
	{
		close(data->fd[i][1]);
		close(data->fd[i][0]);
	}
	lsh_launch(data, pipe);
	exit(0);
}

void child(t_data *data, t_pipe *tmp, int i)
{
	pipe_in_out(i, data, tmp);		
}

int pipe_exec(t_data *data)
{
	int		i;
	int		count;
	int		ret;
	t_pipe *tmp;

	i = 0;
	count = data->pipe_count;
	if (data->pipe_count > 1)
	{
		data->fd = malloc(sizeof(int [2]) * count);
		while (i < count)
		{
			if(pipe(data->fd[i]) == -1)
			{
				// TODO close pipes go to readline
				printf("error\n");
				return (1);   // mtacel                
			}
			i++;
		}
	}
	i = 0;
	tmp = data->pipe;
	while (tmp)
	{
		pid_t id = fork();
		if (id == -1)
		{
			perror("Error: fork\n");
			// TODO close pipes
		}
		if (id == 0)
		{
			child(data, tmp, i);
		}
		tmp = tmp->next;
		i++;
	}
	i = -1;
	while (data->fd && ++i < count)
	{
		close(data->fd[i][1]);
		close(data->fd[i][0]);
	}
	i = -1;
	while (++i < count)
		waitpid(-1, &ret, 0);
	if (WIFSIGNALED(ret))
		return (WTERMSIG(ret) + 127);  // TODO cat | ls   exit code
	if (WIFEXITED(ret)/* && printf("barev\n") && printf("%d\n", WEXITSTATUS(ret))*/)
		return (WEXITSTATUS(ret));
	return (0);
}
