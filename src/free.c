#include "minishell.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

void    free_redirect(t_redirect *redirect)
{
	t_redirect *prev;

    while (redirect)
    {
		prev = redirect;
        free(redirect->f_name);
		redirect = redirect->next;
        free(prev);
    }
}

void    free_pipe(t_pipe *pipe)
{
	t_pipe *prev;

    while (pipe)
    {
		prev = pipe;
        free(pipe->content);
        free(pipe->joined_argv);
        free_matrix(pipe->argv);
        free_redirect(pipe->red);
		pipe = pipe->next;
        free(prev);
    }
}

void	free_data(t_data *data)
{
	data->pipe_count = 0;   // 0
	data->len_key_sum = 0;  // 0
	data->len_val_sum = 0;  // 0
	free(data->fd);
	data->fd = NULL; // read-0 write-1  // NULL
	free_pipe(data->pipe);
	data->pipe = NULL;        // NULL
}

