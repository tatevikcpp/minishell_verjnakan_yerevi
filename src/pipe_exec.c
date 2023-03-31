/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:29:33 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 19:55:01 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void child(t_data *data, t_pipe *tmp, int i)
{
	pipe_in_out(i, data, tmp);		
}

static int ft_waitpid(t_data *data)
{
	int		i;
	int		ret;
	
	i = -1;
	while (++i < data->pipe_count)
		waitpid(-1, &ret, 0);
	if (WIFSIGNALED(ret))
		return (WTERMSIG(ret) + 127);  // TODO cat | ls   exit code
	if (WIFEXITED(ret)/*printf("%d\n", WEXITSTATUS(ret))*/)
		return (WEXITSTATUS(ret));
	return (0);
}

int pipe_exec(t_data *data)
{
	int		i;
	pid_t pid;
	pid_t first_pid;
	t_pipe *tmp;
	
	data->pipe_fd = dup(0);
	tmp = data->pipe;
	i = 0;
	while (tmp)
	{
		pipe(data->fd1);
		pid = fork();
		if (pid == 0)
			first_pid = pid;
		if (pid == -1 && ft_printf(2, "minishell: fork: %s\n", strerror(errno)))
			return (kill(first_pid, SIGKILL), 1);
		if (pid == 0)
			child(data, tmp, i++);
		close(data->pipe_fd);
		data->pipe_fd = dup(data->fd1[0]);
		close(data->fd1[0]);
		close(data->fd1[1]);
		tmp = tmp->next;
	}
	return (close(data->pipe_fd), ft_waitpid(data));
}
