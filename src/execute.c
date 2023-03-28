#include "minishell.h"

extern int exit_status;

char *access_path(t_data *data, char **args)
{
	char    **split_path;
    int     i;
    char    *str;
    char    *exe;

    i = 0;
    if (access(args[0], F_OK) == 0)
        return (args[0]);
    exe = ft_strjoin("/", args[0]);
    split_path = ft_split(ft_get_value("PATH", data), ':');
    while (split_path[i])
    {
        str = ft_strjoin(split_path[i], exe);
        if(access(str, F_OK) == 0)
        {
            free(exe);
            return(str);
        }
        free(str);
        i++;
    }
    free(exe);
    return(NULL);
}

int lsh_launch(t_data *data, t_pipe *pipe)
{
	char    **args;
    char    *path;

    args = pipe->argv;
    path = access_path(data, args);
    if (!path)
    {
        ft_printf(2, "minishell: %s: command not found\n", pipe->argv[0]);
        exit_status = 127;
        return (EXIT_FAILURE);
    }
	if(execve(path, args, data->env) == -1)
    {
		ft_printf(2, "minishell: %s: Permission denied", args[0]);
        exit_status = 126;
    }
	return (1);
}

// void execute(t_data *data, char *ptr)
// {
//     if (data->pipe_count > 1)
//     {
//         // heredoc(data.pipe->red);
//         pipe_exec(data, data->pipe->red);
//     }
//     if(data->pipe_count == 1)
//     {
//         if (there_is_builtin(data) == 1) 
//         {
//             choose_builtin(/* ptr, */ data->pipe, data);
//         }
//         else
//         {
//             // heredoc(data.pipe->red, data.pipe);
//             // infile(data.pipe->red, data.pipe);
//             // outfile(data.pipe->red, data.pipe);
//             // append_red(data.pipe->red, data.pipe);
//             pipe_exec(data, data->pipe->red);
//         }			
//     }
// }